/*
** cmd_setuser.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Wed Dec  4 04:52:46 2002 jean-yves tourtet
** Last update Wed Dec  4 05:41:52 2002 jean-yves tourtet
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


void	cmd_setuser(t_ftpserv *ftpserv, t_client *client, char *args)
{
  char	*tmp;

  args = remove_lspace(args);
  if ((tmp = strchr(args, ' ')))
    *tmp = 0;
  client->username = strdup(args);
  send_msg2client(client, "331 Password required for ");
  send_msg2client(client, client->username);
  send_msg2client(client, "\r\n");
}
