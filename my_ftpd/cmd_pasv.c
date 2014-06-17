/*
** cmd_pasv.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 11:33:41 2002 nicolas vigier
** Last update Wed Dec  4 07:03:03 2002 nicolas vigier
*/

#include <stdio.h>
#include <stdlib.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd_pasv.h"
#include "passiv_mode.h"
#include "netutils.h"
#include "utils.h"

void	cmd_pasv(t_ftpserv *ftpserv, t_client *client, char *args)
{
  char	*tmp;

  client->data_servfd = make_waiting_socket(ftpserv, client);
  send_msg2client(client, "227 Entering Passive Mode (127,0,0,1,");
  tmp = my_itoa(client->data_port / 256);
  printf("tmp = %s\n", tmp);
  send_msg2client(client, tmp);
  send_msg2client(client, ",");
  free(tmp);
  tmp = my_itoa(client->data_port % 256);
  send_msg2client(client, tmp);
  send_msg2client(client, ")\r\n");
  free(tmp);
  client->mode = MODE_PASV;
}
