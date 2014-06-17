/*
** cmd.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Nov 30 23:29:05 2002 nicolas vigier
** Last update Wed Dec  4 04:57:55 2002 jean-yves tourtet
*/

#include "main_serv.h"
#include "serv_cl.h"
#include "cmd.h"
#include "netutils.h"

int	test_logged(t_client *client)
{
  if (!client->autentified)
    {
      send_msg2client(client, "530 Login with USER/PASS first.\r\n");
      return 1;
    }
  return 0;
}
