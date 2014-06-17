/*
** cmd_type.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 09:32:08 2002 nicolas vigier
** Last update Wed Dec  4 05:49:24 2002 nicolas vigier
*/

#include "main_serv.h"
#include "serv_cl.h"
#include "cmd_type.h"
#include "strutils.h"
#include "netutils.h"

void	cmd_type(t_ftpserv *ftpserv, t_client *client, char *args)
{
  args = remove_lspace(args);
  if (*args == 'A' || *args == 'a')
    {
      client->type = TYPE_ASCII;
      send_msg2client(client, "200 Type set to A.\r\n");
      return ;
    }
  if (*args == 'I' || *args == 'i')
    {
      client->type = TYPE_IMAGE;
      send_msg2client(client, "200 Type set to I.\r\n");
      return ;
    }
  send_msg2client(client, "504 Type not implemented.\r\n");
}
