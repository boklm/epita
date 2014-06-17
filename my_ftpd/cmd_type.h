/*
** cmd_type.h for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 09:33:57 2002 nicolas vigier
** Last update Tue Dec  3 09:35:50 2002 nicolas vigier
*/

#define TYPE_ASCII	1
#define	TYPE_IMAGE	2

void	cmd_type(t_ftpserv *ftpserv, t_client *client, char *args);
