/*
** server.h for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Nov 30 20:46:44 2002 nicolas vigier
** Last update Tue Dec  3 10:40:36 2002 nicolas vigier
*/

#ifndef MAIN_SERV_H
#define MAIN_SERV_H

struct	s_ftpserv
{
  int	port;
  int	sockfd;
  char	*welcomestr;
  int	anonymousmode;
  int	usersmode;
  int	min_dataport;
  int	max_dataport;
  int	set_verbose;
  int	verbose_mode;
  char	*logfile_name;
  char	*configfile;
  int	logfile_fd;
};
typedef struct s_ftpserv t_ftpserv;

int			main_serv(t_ftpserv *ftpserv);

#endif /*!MAIN_SERV_H */
