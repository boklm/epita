/*
** passiv_mode.h for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Dec  4 00:09:25 2002 nicolas vigier
** Last update Wed Dec  4 01:43:48 2002 nicolas vigier
*/

int		make_waiting_socket(t_ftpserv *ftpserv, t_client *client);
int		passiv_connect(t_ftpserv *ftpserv, t_client *client);
