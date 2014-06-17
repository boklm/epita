/*
** main.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 20:00:11 2002 nicolas vigier
** Last update Wed Nov 20 06:12:34 2002 nicolas vigier
*/

#include <stdlib.h>
#include "minishell.h"

static t_shell		*new_shell(char *execname)
{
  t_shell		*shell;

  shell = malloc(sizeof (t_shell));
  shell->execname = execname;
  shell->list_modules = NULL;
  shell->noexit = 42;
  return shell;
}

int		main(int argc, char *argv[])
{
  t_shell	*shell;
  int		tmp;

  tmp = argc;
  shell = new_shell(argv[0]);
  return prompt(shell);
}
