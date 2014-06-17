/*
** cmd.h for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Nov 30 23:56:47 2002 nicolas vigier
** Last update Wed Dec  4 04:55:16 2002 jean-yves tourtet
*/

#define CHECK_AUTH(client)	if (test_logged(client)) \
					return ;

int	test_logged(t_client *client);

