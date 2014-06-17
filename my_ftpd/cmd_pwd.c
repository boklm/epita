/*
** cmd_pwd.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Wed Dec  4 04:17:06 2002 jean-yves tourtet
** Last update Wed Dec  4 04:36:54 2002 jean-yves tourtet
*/

#include <unistd.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd.h"
#include "utils.h"
#include "netutils.h"

void	cmd_pwd(t_ftpserv *ftpserv, t_client *client, char *args)
{
  char *pwd;

  CHECK_AUTH(client);
  pwd = xmalloc(sizeof (char) * 1024);
  getcwd(pwd, 1024);
  send_msg2client(client, "257 \"");
  send_msg2client(client, pwd);
  send_msg2client(client, "\" is current directory.\r\n");
}
