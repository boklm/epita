/*
** logging.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 04:07:18 2002 nicolas vigier
** Last update Tue Dec  3 10:26:10 2002 nicolas vigier
*/

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include "main_serv.h"
#include "logging.h"
#include "utils.h"

static t_bufstr	*initbufstr(void)
{
  t_bufstr	*res;

  res = xmalloc(sizeof (t_bufstr));
  res->n = 0;
  res->str = xmalloc(BUFSTR_SIZE);
  return res;
};

static void	cleanbuf(t_bufstr *bufstr, int fd)
{
  if (bufstr->n == 0)
    return ;
  write(fd, bufstr->str, bufstr->n);
  bufstr->n = 0;
}

static void	buf_putc(t_bufstr *bufstr, int fd, char c)
{
  if (bufstr->n >= BUFSTR_SIZE)
    cleanbuf(bufstr, fd);
  bufstr->str[bufstr->n++] = c;
}

static void	bufwrite(t_bufstr *bufstr, int fd, char *str)
{
  while (*str)
    buf_putc(bufstr, fd, *(str++));
}

static void	write_date(t_bufstr *bufstr, t_ftpserv *ftpserv)
{
  char		tmp[26];
  time_t	ltime;

  ltime = time(NULL);
  ctime_r(&ltime, tmp);
  tmp[strlen(tmp) - 1] = 0;
  bufwrite(bufstr, ftpserv->logfile_fd, tmp);
  bufwrite(bufstr, ftpserv->logfile_fd, ": ");
}

int	open_logfile(t_ftpserv *ftpserv)
{
  if (!ftpserv->logfile_name)
    return -1;
  if ((ftpserv->logfile_fd = open(ftpserv->logfile_name,
				  O_WRONLY | O_APPEND | O_CREAT, 0666)) == -1)
    {
      write(STDERR_FILENO, "Error. Can't open open file ", 27);
      write(STDERR_FILENO, ftpserv->logfile_name, strlen(ftpserv->logfile_name));
      write(STDERR_FILENO, " for writing\n Exiting...\n", 25);
      exit(1);
    }
  write(ftpserv->logfile_fd, "Starting logging\n", 17);
  return 1;
}

int		logline(t_ftpserv *ftpserv, int n, char *str, ...)
{
  va_list	ap;
  t_bufstr	*bufstr;

  if (n > ftpserv->verbose_mode || !ftpserv->logfile_name)
    return 0;
  bufstr = initbufstr();
  write_date(bufstr, ftpserv);
  va_start(ap, str);
  while (*str)
    {
      if (*str == '^')
	bufwrite(bufstr, ftpserv->logfile_fd, va_arg(ap, char *));
      else
	buf_putc(bufstr, ftpserv->logfile_fd, *str);
      str++;
    }
  cleanbuf(bufstr, ftpserv->logfile_fd);
  va_end(va);
  free(bufstr->str);
  free(bufstr);
  return 1;
}
