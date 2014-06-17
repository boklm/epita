/*
** activ_mode.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Dec  2 01:28:47 2002 nicolas vigier
** Last update Wed Dec  4 02:05:45 2002 nicolas vigier
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "activ_mode.h"
#include "netutils.h"

int			make_connect_socket(t_client *client)
{
  struct sockaddr_in	serv_addr;
  struct hostent	*server;

  client->data_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (client->data_fd < 0)
    {
      send_msg2client(client, "ERROR opening socket\r\n");
      exit(1);
    }
  server = gethostbyname(client->ip);
  if (server == NULL)
    {
      send_msg2client(client, "ERROR, no such host\r\n");
      exit(1);
    }
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
	(char *)&serv_addr.sin_addr.s_addr,
	server->h_length);
  serv_addr.sin_port = htons(client->data_port);
  if (connect(client->data_fd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
    send_msg2client(client, "ERROR connecting\r\n");
  return 1;
}
