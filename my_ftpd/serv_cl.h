/*
** serv_cl.h for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Nov 30 23:06:54 2002 nicolas vigier
** Last update Wed Dec  4 07:47:03 2002 nicolas vigier
*/

#ifndef SERV_CL_H
#define SERV_CL_H

#define MODE_NULL	0
#define MODE_ACTF	1
#define MODE_PASV	2

typedef struct	s_client
{
  int		fd;
  char		*username;
  char		*passwd;
  char		*homedirectory;
  int		autentified;
  int		mode;
  int		data_fd;
  int		data_servfd;
  int		data_port;
  int		data_pid;
  int		type;
  char		*ip;
  int		noexit;
}			t_client;

int	serv_cl(t_ftpserv *ftpserv, t_client *client);

#endif /* !SERV_CL_H */
