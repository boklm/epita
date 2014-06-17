/*
** exec_prg.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 12:08:18 2002 nicolas vigier
** Last update Wed Nov 20 05:36:07 2002 nicolas vigier
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "minishell.h"

static int	lst_size(t_lst *lst)
{
  int		res;

  res = 0;
  while (lst)
    {
      lst = lst->next;
      res++;
    }
  return res;
}

static void	make_args(t_prg *prg)
{
  t_lst		*tmp;
  int		n;
  char		*str;

  if (!(tmp = prg->list_args))
    error_msg(ERR_PARS);
  n = lst_size(tmp);
  prg->args = mmalloc(sizeof (char *) * n + 1);
  prg->args[n] = NULL;
  while (n--)
    {
      str = tmp->ptr;
      prg->args[n] = *str ? str : NULL;
      tmp = tmp->next;
    }
}

int	exec_prg(t_shell *shell, t_prg *prg)
{
  int	res;

  if (prg->infd != STDIN_FILENO)
    dup2(prg->infd, STDIN_FILENO);
  if (prg->outfd != STDOUT_FILENO)
    dup2(prg->outfd, STDOUT_FILENO);
  if (!prg->args)
    make_args(prg);
  if (check_bt(shell, prg, 0) == -1)
    res = execvp(*prg->args, prg->args);
  perror("minishell");
  exit(1);
  return res;
}

int	forknexec_prg(t_shell *shell, t_prg *prg)
{
  int	pid;
  int	ret;

  make_args(prg);
  if ((ret = check_load(shell, prg)) != -1)
    return ret;
  if ((ret = check_bt(shell, prg, 1)) != -1)
    return ret;
  ret = 0;
  if ((pid = fork()) == -1)
    error_msg(ERR_FORK);
  if (pid > 0)
    waitpid(pid, &ret, 0);
  else
    {
      if (prg->async)
	{
	  if ((pid = fork()) == -1)
	    error_msg(ERR_FORK);
	  if (pid > 0)
	    exit(0);
	  else
	    exec_prg(shell, prg);
	}
      else
	exec_prg(shell, prg);
    }
  return ret;
}
