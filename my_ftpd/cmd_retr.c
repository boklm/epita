/*
** cmd_retr.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Dec  2 08:54:32 2002 nicolas vigier
** Last update Wed Dec  4 06:33:54 2002 nicolas vigier
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd_retr.h"
#include "strutils.h"
#include "netutils.h"
#include "activ_mode.h"
#include "passiv_mode.h"
#include "cmd_type.h"
#include "readln.h"
#include "logging.h"

static void	do_retr(t_ftpserv *ftpserv, t_client *client, char *args)
{
  char		*tmp;
  int		infd;

  args = remove_lspace(args);
  if ((infd = open(args, O_RDONLY, 0666)) == -1)
    {
      send_msg2client(client, "451 ");
      send_msg2client(client, strerror(errno));
      send_msg2client(client, "\r\n");
      return ;
    }
  while ((tmp = readln(infd, '\n')))
    if ((write(client->data_fd, tmp, strlen(tmp)) == -1)
	|| write(client->data_fd, client->type == TYPE_ASCII ? "\r\n" : "\n",
		 client->type == TYPE_ASCII ? 2 : 1) == -1)
      {
	send_msg2client(client, "451 ");
	send_msg2client(client, "error sending file.\r\n");
	break ;
      }
  close(infd);
}

void	cmd_retr(t_ftpserv *ftpserv, t_client *client, char *args)
{
  int	pid;

  logline(ftpserv, 1, "user ^ retr ^.\n", client->username, args);
  if ((pid = fork()) == -1)
    {
      send_msg2client(client, "451 fork error. Please try again later.\r\n");
      return ;
    }
  if (pid == 0)
    {
      if (client->mode == MODE_ACTF)
	make_connect_socket(client);
      send_msg2client(client, "150 Opening data connection.\r\n");
      if (client->mode == MODE_PASV)
	passiv_connect(ftpserv, client);
      do_retr(ftpserv, client, args);
      shutdown(client->data_fd, SHUT_RDWR);
      close(client->data_fd);
      if (client->mode == MODE_PASV)
	close(client->data_servfd);
      send_msg2client(client, "226 Transfer complete.\r\n");
    }
}
