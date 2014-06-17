/*
** cmd_setpass.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Wed Dec  4 04:53:21 2002 jean-yves tourtet
** Last update Wed Dec  4 06:40:42 2002 nicolas vigier
*/

#include <unistd.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd.h"
#include "netutils.h"
#include "strutils.h"
#include "utils.h"
#include "user_ident.h"
#include "logging.h"

void	cmd_setpass(t_ftpserv *ftpserv, t_client *client, char *args)
{
  if (!client->username)
    {
      send_msg2client(client, "503 No username. Login with USER first.\r\n");
      return ;
    }
  args = remove_lspace(args);
  client->passwd = args;
  if (ftpserv->anonymousmode && (!strcmp(client->username, "anonymous") ||
				 !strcmp(client->username, "ftp")))
    {
      client->autentified = 1;
      send_msg2client(client, "230 Welcome anonymous user\r\n");
      logline(ftpserv, 0, "user ^ has logged.\n", client->username);
      return ;
    }
  if (user_ident(client))
    {
      send_msg2client(client, "230 Acces granted.\r\n");
      client->autentified = 1;
      logline(ftpserv, 0, "user ^ has logged.\n", client->username);
      chdir(client->homedirectory);
    }
  else
    {
      send_msg2client(client,
		 "530 passwd not ok. You'll be more lucky next time.\r\n");
      client->noexit = 0;
    }
}
