/*
** prompt.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 19:53:33 2002 nicolas vigier
** Last update Wed Nov 20 00:39:23 2002 nicolas vigier
*/

#include <stdlib.h>
#include "minishell.h"

static void	free_lst(t_lst	*lst)
{
  t_lst		*next;

  while (lst)
    {
      next = lst->next;
      free(lst->ptr);
      free(lst);
      lst = next;
    }
}

static void	free_prg(t_prg *prg)
{
  free_lst(prg->list_args);
  if (prg->infile)
    {
      free(prg->infile);
      close(prg->infd);
    }
  if (prg->outfile)
    {
      free(prg->outfile);
      close(prg->outfd);
    }
  free(prg);
}

int	prompt(t_shell *shell)
{
  char	*cmd;
  t_prg	*newprg;

  while (shell->noexit)
    {
      write(STDOUT_FILENO, "$ ", 2);
      cmd = readln();
      newprg = new_prg();
      pars_exec_cmd(shell, cmd, newprg, 1);
      free(cmd);
      free_prg(newprg);
    }
  return 0;
}
