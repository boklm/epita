/*
** cmd_list.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Dec  2 01:22:11 2002 nicolas vigier
** Last update Wed Dec  4 02:10:52 2002 nicolas vigier
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd_list.h"
#include "activ_mode.h"
#include "netutils.h"
#include "activ_mode.h"
#include "passiv_mode.h"
#include "readln.h"
#include "strutils.h"
#include "cmd_type.h"

static int	do_ls(t_ftpserv *ftpserv, t_client *client, char *args)
{
  int		pid;
  int		p[2];
  char		*tmp[4];
  char		*str;

  args = remove_lspace(args);
  pipe(p);
  if ((pid = fork()) != -1)
    {
      if (!pid)
	{
	  close(p[0]);
	  dup2(p[1], STDOUT_FILENO);
	  dup2(p[1], STDERR_FILENO);
	  tmp[0] = "/bin/ls";
	  tmp[1] = "-l";
	  tmp[2] = NULL;
	  execv(tmp[0], tmp);
	  perror("ls");
	  exit(1);
	}
      else
	{
	  close(p[1]);
	  while ((str = readln(p[0], '\n')))
	    {
	      write(client->data_fd, str, strlen(str));
	      if (client->type == TYPE_ASCII)
		write(client->data_fd, "\r\n", 2);
	      else
		write(client->data_fd, "\n", 2);
	    }
	}
    }
  return 1;
}

void	cmd_list(t_ftpserv *ftpserv, t_client *client, char *args)
{
  int	pid;

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
      do_ls(ftpserv, client, args);
      shutdown(client->data_fd, SHUT_RDWR);
      close(client->data_fd);
      if (client->mode == MODE_PASV)
	close(client->data_servfd);
      send_msg2client(client, "226 Transfer complete.\r\n");
      exit(0);
    }
}
