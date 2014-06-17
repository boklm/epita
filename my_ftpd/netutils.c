/*
** netutils.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Nov 30 23:46:21 2002 nicolas vigier
** Last update Sun Dec  1 00:17:27 2002 nicolas vigier
*/

#include <string.h>
#include <unistd.h>
#include "main_serv.h"
#include "serv_cl.h"

int	send_msg2client(t_client *client, char *msg)
{
  int	size;

  size = strlen(msg);
  if (write(client->fd, msg, size) == -1)
    {
      client->noexit = 0;
      return 0;
    }
  return 1;
}
