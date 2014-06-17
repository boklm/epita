/*
** cmd_unknow.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Wed Dec  4 04:50:55 2002 jean-yves tourtet
** Last update Wed Dec  4 05:42:30 2002 jean-yves tourtet
*/

#include <string.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd.h"
#include "netutils.h"
#include "strutils.h"
#include "utils.h"
#include "user_ident.h"
#include "logging.h"

void	cmd_unknown(t_ftpserv *ftpserv, t_client *client, char *args)
{
  char	*tmp;

  args = remove_lspace(args);
  if (*args)
    {
      if ((tmp = strchr(args, ' ')))
	*tmp = 0;
      send_msg2client(client, "500 Game Over. ");
      send_msg2client(client, args);
      send_msg2client(client, " is not a supported command.\r\n");
    }
}
