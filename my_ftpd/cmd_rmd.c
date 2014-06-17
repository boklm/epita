/*
** cmd_rmd.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Wed Dec  4 04:49:15 2002 jean-yves tourtet
** Last update Wed Dec  4 06:33:34 2002 nicolas vigier
*/

#include <unistd.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd.h"
#include "netutils.h"
#include "strutils.h"
#include "utils.h"
#include "logging.h"

void	cmd_rmd(t_ftpserv *ftpserv, t_client *client, char *args)
{
  CHECK_AUTH(client);
  logline(ftpserv, 0, "user ^ rmd ^.\n", client->username, args);
  args = remove_lspace(args);
  if (*args)
    {
      if (rmdir(args) == 0)
	send_msg2client(client,
			"250 Requested directory action okay, completed.\r\n");
      else
	{
	  send_msg2client(client,
			  "450 Requested directory action not taken.\r\n");
	  send_msg2client(client, "    Directory unavailable.\r\n");
	}
    }
}
