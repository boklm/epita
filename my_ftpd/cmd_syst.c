/*
** cmd_syst.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Dec  4 07:07:58 2002 nicolas vigier
** Last update Wed Dec  4 07:19:10 2002 nicolas vigier
*/

#include <sys/utsname.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd_syst.h"
#include "netutils.h"

void			cmd_syst(t_ftpserv *ftpserv, t_client *client, char *args)
{
  struct utsname	name;

  send_msg2client(client, "215 UNIX Type: L8 Version: ");
  uname(&name);
  send_msg2client(client, name.sysname);
  send_msg2client(client, " ");
  send_msg2client(client, name.release);
  send_msg2client(client, "\r\n");
}
