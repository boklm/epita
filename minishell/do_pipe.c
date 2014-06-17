/*
** do_pipe.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 11:48:44 2002 nicolas vigier
** Last update Wed Nov 20 04:58:18 2002 nicolas vigier
*/

#include <sys/wait.h>
#include "minishell.h"

int	do_pipe_(t_shell *shell, t_prg *prg)
{
  int  	pid;
  int	p[2];
  t_prg	*newprg;

  if (pipe(p) < 0)
    error_msg(ERR_PIPE);
  if ((pid = fork()) == -1)
    error_msg(ERR_FORK);
  if (pid > 0)
    {
      close(p[1]);
      newprg = new_prg();
      newprg->infd = p[0];
      newprg->infile = ERR_PARS;
      return pars_exec_cmd(shell, prg->ptr + 1, newprg, 0);
    }
  close(p[0]);
  prg->outfd = p[1];
  return exec_prg(shell, prg);
}

int	do_pipe(t_shell *shell, t_prg *prg)
{
  int	pid;
  int	ret;

  if ((pid = fork()) == -1)
    error_msg(ERR_FORK);
  if (pid > 0)
    waitpid(pid, &ret, 0);
  else
    {
      do_pipe_(shell, prg);
      exit(0);
    }
  return ret;
}
