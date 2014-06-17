/*
** server.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Nov 30 20:46:30 2002 nicolas vigier
** Last update Tue Dec  3 09:52:08 2002 nicolas vigier
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "error.h"
#include "utils.h"
#include "cmd_type.h"

static int		make_listen_socket(t_ftpserv *ftpserv);
static	t_client	*make_newclient(int newsockfd);

static int		make_listen_socket(t_ftpserv *ftpserv)
{
  int			sockfd;
  struct sockaddr_in	serv_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    exit_error("ERROR opening socket");
  bzero((char *) &serv_addr, sizeof (serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(ftpserv->port);
  if (bind(sockfd, (struct sockaddr *) &serv_addr,
	   sizeof (serv_addr)) < 0)
    exit_error("ERROR on binding");
  listen(sockfd, 5);
  return sockfd;
}

static	t_client	*make_newclient(int newsockfd)
{
  t_client		*res;

  res = xmalloc(sizeof (t_client));
  res->fd = newsockfd;
  res->username = NULL;
  res->mode = 0;
  res->data_fd = 0;
  res->data_port = 0;
  res->noexit = 1;
  res->type = TYPE_ASCII;
  return res;
}

int			main_serv(t_ftpserv *ftpserv)
{
  int			newsockfd;
  struct sockaddr_in	cli_addr;
  int			pid;
  t_client		*newclient;
  int			clilen;

  ftpserv->sockfd = make_listen_socket(ftpserv);
  clilen = sizeof (cli_addr);
  while (42)
    {
      newsockfd = accept(ftpserv->sockfd,
			 (struct sockaddr *) &cli_addr,
			 &clilen);
      if ((pid = fork()) == -1)
	exit_perror("fork");
      if (pid == 0)
	{
	  newclient = make_newclient(newsockfd);
	  serv_cl(ftpserv, newclient);
	  exit(0);
	}
    }
  return 0;
}
