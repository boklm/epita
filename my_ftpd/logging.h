/*
** logging.h for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 04:44:26 2002 nicolas vigier
** Last update Tue Dec  3 07:05:37 2002 nicolas vigier
*/

#define BUFSTR_SIZE	50

struct	s_bufstr
{
  char	*str;
  int	n;
};
typedef struct s_bufstr t_bufstr;

int	logline(t_ftpserv *ftpserv, int n, char *str, ...);
int	open_logfile(t_ftpserv *ftpserv);
