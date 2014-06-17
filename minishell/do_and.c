/*
** do_and.c for nimishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 18:28:44 2002 nicolas vigier
** Last update Tue Nov 19 13:00:24 2002 nicolas vigier
*/

#include "minishell.h"

int	do_and(t_shell *shell, t_prg *prg)
{
  int	ret;
  t_prg	*newprg;

  if ((ret = forknexec_prg(shell, prg)))
    return ret;
  newprg = new_prg();
  return pars_exec_cmd(shell, prg->ptr + 2, newprg, 1);
}
