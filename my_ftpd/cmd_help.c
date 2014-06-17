/*
** cmd_help.c for my_ftpd in .
** 
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
** 
** Started on  Wed Dec  4 04:51:44 2002 jean-yves tourtet
** Last update Wed Dec  4 05:48:40 2002 jean-yves tourtet
*/

#include <string.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd.h"
#include "netutils.h"
#include "strutils.h"
#include "utils.h"
#include "help.h"

void	cmd_help(t_ftpserv *ftpserv, t_client *client, char *args)
{
  char *tmp;

  args = remove_lspace(args);
  if (!(*args))
    {
      send_msg2client(client,
		      "214-The following commands are recognized.\r\n");
      send_msg2client(client,
		      "214-USER    PASS    QUIT    CWD     PWD\r\n");
      send_msg2client(client,
		      "214-LIST    HELP    STAT    SYST    SIZE\r\n");
      send_msg2client(client,
		      "214-MKD     RMD     DELE    STOR    RETR\r\n");
      send_msg2client(client,
		      "214 end.\r\n");
    }
  else
    {
      if ((tmp = strchr(args, ' ')))
	*tmp = 0;
      help_func(client, args);
    }
}
