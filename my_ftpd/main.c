/*
** main.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Dec  1 00:23:28 2002 nicolas vigier
** Last update Wed Dec  4 05:48:34 2002 nicolas vigier
*/

#include <stdlib.h>
#include "main_serv.h"
#include "utils.h"
#include "logging.h"
#include "getopt.h"
#include "listc.h"
#include "cf.h"

static void    	init_defaults(t_ftpserv *ftpserv)
{
  ftpserv->port = 3434;
  ftpserv->welcomestr = "Welcome to RushFTPD V0.01a";
  ftpserv->anonymousmode = 0;
  ftpserv->verbose_mode = 0;
  ftpserv->logfile_name = NULL;
  ftpserv->min_dataport = 4000;
  ftpserv->max_dataport = 5000;
}

static char	*ifnotnulstr(char *a, char *b)
{
  return a ? a : b;
}

static int	ifnotnulnbr(char *a, int b)
{
  return a ? atoi(a) : b;
}

static void	load_configfile(t_ftpserv *ftpserv)
{
  t_listc	*config;

  if (ftpserv->configfile && (config = cf_read_file(ftpserv->configfile)))
    {
      ftpserv->welcomestr =
	ifnotnulstr(cf_return_value(config, "welcomemsg"),
		    ftpserv->welcomestr);
      ftpserv->logfile_name =
	ifnotnulstr(cf_return_value(config, "logfile"),
		    ftpserv->logfile_name);
      ftpserv->verbose_mode =
	ifnotnulnbr(cf_return_value(config, "loglevel"),
		    ftpserv->verbose_mode);
      ftpserv->anonymousmode =
	ifnotnulnbr(cf_return_value(config, "anonymousmode"),
		    ftpserv->anonymousmode);
      ftpserv->max_dataport =
	ifnotnulnbr(cf_return_value(config, "max_dataport"),
		    ftpserv->max_dataport);
      ftpserv->min_dataport =
	ifnotnulnbr(cf_return_value(config, "min_dataport"),
		    ftpserv->min_dataport);
    }
}

int		main(int argc, char *argv[])
{
  t_ftpserv	*ftpserv;

  ftpserv = xmalloc(sizeof (t_ftpserv));
  init_defaults(ftpserv);
  getoptargs(argc, argv, ftpserv);
  load_configfile(ftpserv);
  open_logfile(ftpserv);
  main_serv(ftpserv);
  return 0;
}
