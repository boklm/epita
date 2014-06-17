/*
** cmd_quit.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Wed Dec  4 04:06:06 2002 jean-yves tourtet
** Last update Wed Dec  4 04:37:52 2002 jean-yves tourtet
*/

#include "main_serv.h"
#include "serv_cl.h"
#include "netutils.h"
#include "logging.h"

void	cmd_quit(t_ftpserv *ftpserv, t_client *client, char *args)
{
  send_msg2client(client, "221 GoodBye.\r\n");
  client->noexit = 0;
  logline(ftpserv, 0, "user ^ has logged out\n", client->username);
}
