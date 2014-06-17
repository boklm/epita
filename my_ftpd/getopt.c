/*
** getopt.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 09:56:42 2002 nicolas vigier
** Last update Wed Dec  4 06:05:03 2002 nicolas vigier
*/

#include <stdio.h>
#include <stdlib.h>
#include "main_serv.h"
#include "getopt.h"

static void	print_version(void)
{
  printf("RushFTPD V0.01a\n");
  exit(0);
}

static void	print_syn(int n)
{
  printf("ftpd [-f config_file] [-p <port>] [-U<n> <logfile>] [-v] [-a]\n");
  exit(n);
}

static char	*test_nulstr(char *str)
{
  if (!str)
    print_syn(1);
  return str;
}

static void	anonymous_only(t_ftpserv *ftpserv)
{
  ftpserv->anonymousmode = 1;
  ftpserv->usersmode = 0;
}

static void	setlogfile(t_ftpserv *ftpserv, int n, char *filename)
{
  if (n < 0)
    print_syn(1);
  ftpserv->verbose_mode = n;
  ftpserv->logfile_name = filename;
}

void	getoptargs(int argc, char *argv[],
		   t_ftpserv *ftpserv)
{
  int	i;
  char	*tmp;

  for (i = 1; i < argc; i++)
    {
      tmp = argv[i];
      if (*tmp++ != '-')
	print_syn(1);
      if (*tmp == 'V')
	print_version();
      if (*tmp == 'a')
	anonymous_only(ftpserv);
      else if (*tmp == 'v')
	ftpserv->set_verbose = 1;
      else if (*tmp == 'p')
	  ftpserv->port = atoi(test_nulstr(argv[++i]));
      else if (*tmp == 'U')
	setlogfile(ftpserv, tmp[1], test_nulstr(argv[++i]));
      else if (*tmp == 'f')
	ftpserv->configfile = test_nulstr(argv[++i]);
      else
	print_syn(1);
    }
}
