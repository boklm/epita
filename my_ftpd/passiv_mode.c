/*
** passiv_mode.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 07:31:49 2002 nicolas vigier
** Last update Wed Dec  4 06:59:14 2002 nicolas vigier
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "passiv_mode.h"
#include "error.h"

int	make_waiting_socket(t_ftpserv *ftpserv, t_client *client)
{
  int	sockfd, newsockfd;
  char	buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int	n;
  int	port;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    exit_perror("socket");
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  port = ftpserv->min_dataport;
  while (port < ftpserv->max_dataport)
    {
      serv_addr.sin_port = htons(port);
      if (!(bind(sockfd, (struct sockaddr *) &serv_addr,
		 sizeof (serv_addr)) < 0))
	break ;
      port++;
    }
  if (port != ftpserv->max_dataport)
    client->data_port = port;
  else
    exit_error("ERROR on binding");
  listen(sockfd, 5);
  return sockfd;
}

int			passiv_connect(t_ftpserv *ftpserv, t_client *client)
{
  int			clilen;
  struct sockaddr_in	cli_addr;

  clilen = sizeof (cli_addr);
  client->data_fd = accept(client->data_servfd,
			   (struct sockaddr *) &cli_addr,
			   &clilen);
  if (client->data_fd < 0)
    {
      printf("accept error\n");
      exit(1);
      return 0;
    }
  return 1;
}
