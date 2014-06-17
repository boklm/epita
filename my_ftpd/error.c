/*
** error.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Nov 30 21:22:26 2002 nicolas vigier
** Last update Sun Dec  1 00:02:52 2002 nicolas vigier
*/

#include <stdio.h>
#include <unistd.h>

int	exit_error(char *msg)
{
  write(STDERR_FILENO, msg, strlen(msg));
  exit(1);
}

int	exit_perror(char *msg)
{
  perror(msg);
  exit(1);
}
