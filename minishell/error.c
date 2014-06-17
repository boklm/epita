/*
** error.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 10:56:03 2002 nicolas vigier
** Last update Tue Nov 19 13:16:59 2002 nicolas vigier
*/

#include <stdio.h>
#include "minishell.h"

void	error_msg(char *msg)
{
  int	msglen;

  msglen = my_strlen(msg);
  write(STDERR_FILENO, msg, msglen);
}

void	exit_perror(char *str)
{
  perror(str);
  exit(1);
}

void	exit_error(char *str)
{
  error_msg(str);
  exit(1);
}
