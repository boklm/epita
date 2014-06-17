/*
** cmd_dele.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Wed Dec  4 04:42:39 2002 jean-yves tourtet
** Last update Wed Dec  4 05:36:54 2002 jean-yves tourtet
*/

#include <sys/stat.h>
#include <stdio.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd.h"
#include "netutils.h"
#include "strutils.h"
#include "utils.h"

void	cmd_dele(t_ftpserv *ftpserv, t_client *client, char *args)
{
  CHECK_AUTH(client);
  args = remove_lspace(args);
  if (*args)
    {
      if (remove(args) == 0)
	send_msg2client(client,
			"250 Requested file action okay, completed.\r\n");
      else
	{
	  send_msg2client(client, "450 Requested file action not taken.\r\n");
	  send_msg2client(client, "    File unavailable.\r\n");
	}
    }
}
