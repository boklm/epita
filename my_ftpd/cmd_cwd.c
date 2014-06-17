/*
** cmd_cwd.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Wed Dec  4 04:22:42 2002 jean-yves tourtet
** Last update Wed Dec  4 04:36:40 2002 jean-yves tourtet
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd.h"
#include "netutils.h"
#include "strutils.h"
#include "utils.h"
#include "error.h"

void	cmd_cwd(t_ftpserv *ftpserv, t_client *client, char *args)
{
  CHECK_AUTH(client);
  args = remove_lspace(args);
  if (chdir(args) != -1)
    send_msg2client(client, "250 CWD command successful.\r\n");
  else
    {
      send_msg2client(client, "550 ");
      send_msg2client(client, args);
      send_msg2client(client, " ");
      send_msg2client(client, strerror(errno));
      send_msg2client(client, "\r\n");
    }
}
