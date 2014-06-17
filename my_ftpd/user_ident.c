/*
** userdata.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Fri Nov 29 17:12:33 2002 jean-yves tourtet
** Last update Tue Dec  3 21:18:16 2002 jean-yves tourtet
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_tools.h"
#include "main_serv.h"
#include "serv_cl.h"
#include "user_ident.h"
#include "pass_ident.h"
#include "error.h"
#include "utils.h"
#include "netutils.h"

static t_client	*result(char *res, int fd, t_client *custom)
{
  char		c, *ident;

  ident = "\0";
  if (my_strcmp(res, custom->username) != 0)
    while ((c != '\n') && (c != '\0'))
      {
	  if (read(fd, &c, 1) == -1)
	    exit_perror("read");
      }
  else
    {
      custom->username = res;
      while ((read(fd, &c, 1) != -1) && (c != '\n'))
	ident = my_strconcat(ident, c);
      custom->homedirectory = ident;
      return custom;
    }
  return custom;
}

static t_client	*read_username(int fd, t_client *custom)
{
  int		eof;
  char		c, *res;

  eof = 0;
  res = "\0";
  while (((eof = read(fd, &c, 1)) != 0) &&
	 (my_strcmp(res, custom->username) != 0))
    {
      res = "\0";
      res = my_strconcat(res, c);
      while ((read(fd, &c, 1) != 0) && (c != ':') && (c != '\n'))
	res = my_strconcat(res, c);
      custom = result(res, fd, custom);
    }
  if ((eof == 0) && (my_strcmp(res, custom->username) != 0))
    {
      custom = 0;
      return custom;
    }
  return custom;
}

static t_client	*userdata(t_client *custom)
{
  int		fd;

  if ((fd = open("users.db", O_RDONLY, 0666)) == -1)
      exit_perror("open");
  custom = read_username(fd, custom);
  close(fd);
  return custom;
}

static int	test_username(char *arg)
{
  if (*arg == '\0')
    return 0;
  return 1;
}

int		user_ident(t_client *custom)
{
  if (test_username(custom->username) == 0)
    return 0;
  if ((custom = userdata(custom)) == 0)
    return 0;
  if (pass_ident(custom) == 0)
    return 0;
  return 1;
}
