/*
** do_or.c for nimishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 18:44:57 2002 nicolas vigier
** Last update Tue Nov 19 13:01:09 2002 nicolas vigier
*/

#include "minishell.h"

int	do_or(t_shell *shell, t_prg *prg)
{
  t_prg	*newprg;

  if (!(forknexec_prg(shell, prg)))
    return 0;
  newprg = new_prg();
  return pars_exec_cmd(shell, prg->ptr + 2, newprg, 1);
}
