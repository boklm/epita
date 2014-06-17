/*
** pars.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 10:43:57 2002 nicolas vigier
** Last update Wed Nov 20 03:58:55 2002 nicolas vigier
*/

#include <stdlib.h>
#include <fcntl.h>
#include "minishell.h"

t_prg	*new_prg(void)
{
  t_prg	*res;

  res = mmalloc(sizeof (t_prg));
  res->args = NULL;
  res->outfd = STDOUT_FILENO;
  res->infd = STDIN_FILENO;
  res->infile = NULL;
  res->outfile = NULL;
  res->list_args = NULL;
  res->appendfile = 0;
  res->async = 0;
  return res;
}

static char	*read_str(t_prg *prg)
{
  char		*res;

  while (*prg->ptr == ' ')
    prg->ptr++;
  if (*prg->ptr == '"')
    {
      res = ++prg->ptr;
      while (*prg->ptr++ != '"')
	;
      return my_strndup(res, prg->ptr - res - 1);
    }
  res = prg->ptr;
  while ((*prg->ptr != ' ') && (*prg->ptr != '&') && (*prg->ptr != '|')
	 && (*prg->ptr))
    prg->ptr++;
  return my_strndup(res, prg->ptr - res);
}

static void	set_outputfile(t_prg *prg)
{
  if (prg->outfile)
    error_msg(ERR_PARS);
  prg->ptr++;
  if (*prg->ptr == '>')
    {
      prg->ptr++;
      prg->appendfile = 1;
    }
  prg->outfile = read_str(prg);
  prg->outfd = open(prg->outfile, prg->appendfile ? O_WRONLY | O_APPEND | O_CREAT
		    : O_WRONLY | O_TRUNC | O_CREAT, 0666);
  if (prg->outfd == -1)
    exit_perror("minishell");
}

static void	set_inputfile(t_prg *prg)
{
  if (prg->infile)
    error_msg(ERR_PARS);
  prg->ptr++;
  prg->infile = read_str(prg);
  prg->infd = open(prg->infile, O_RDONLY, 0666);
  if (prg->infd == -1)
    error_msg(ERR_FILE);
}

static void	set_async(t_prg *prg)
{
  prg->async = 1;
  prg->ptr++;
}

static t_prg	*check_prg(t_prg *prg)
{
  return prg;
}

int	pars_exec_cmd(t_shell *shell, char *str, t_prg *prg, int fork)
{
  prg->ptr = str;
  while (*prg->ptr)
    {
      if (*prg->ptr == ' ')
	prg->ptr++;
      if (*prg->ptr == '&' && *(prg->ptr + 1) == '&')
	return do_and(shell, check_prg(prg));
      if (*prg->ptr == '&')
	  set_async(prg);
      else if (*prg->ptr == '|' && *(prg->ptr + 1) == '|')
	return do_or(shell, check_prg(prg));
      else if (*prg->ptr == '|')
	return do_pipe(shell, check_prg(prg));
      else if (*prg->ptr == '>')
	set_outputfile(prg);
      else if (*prg->ptr == '<')
	set_inputfile(prg);
      else prg->list_args = lst_add_elt(prg->list_args, read_str(prg));
    }
  if (!prg->list_args)
    return 0;
  return fork ? forknexec_prg(shell, prg) : exec_prg(shell, prg);
}
