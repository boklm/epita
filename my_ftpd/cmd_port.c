/*
** cmd_port.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Dec  2 00:22:02 2002 nicolas vigier
** Last update Wed Dec  4 02:01:46 2002 nicolas vigier
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd_port.h"
#include "netutils.h"

static int	pars_error(t_client *client)
{
  send_msg2client(client, "500 Pars error\r\n");
  return 1;
}

void	cmd_port(t_ftpserv *ftpserv, t_client *client, char *args)
{
  int	i;
  char	*tmp;
  char	*tmp2;

  tmp = strchr(args, ',');
  for (i = 0; i < 3; i++)
    {
      if (!tmp && pars_error(client))
	  return ;
      *tmp = '.';
      tmp = strchr(tmp, ',');
    }
  if (!tmp && pars_error(client))
      return ;
  *tmp++ = 0;
  tmp2 = strchr(tmp, ',');
  if (!tmp2 && pars_error(client))
      return ;
  *tmp2++ = 0;
  if (!*tmp && pars_error(client))
      return ;
  client->data_port = 256 * atoi(tmp) + atoi(tmp2);
  client->ip = strdup(args);
  client->mode = MODE_ACTF;
  send_msg2client(client, "200 PORT command successful.\r\n");
}
