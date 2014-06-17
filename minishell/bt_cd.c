/*
** bt_cd.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Nov 19 14:27:11 2002 nicolas vigier
** Last update Wed Nov 20 05:32:37 2002 nicolas vigier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	bt_type(void)
{
  return 1;
}

char	*bt_name(void)
{
  return "cd";
}

int	exec_bt(char **args)
{
  if (!args[1])
    {
      if (chdir(getenv("HOME")) == -1)
	{
	  perror("cd");
	  return 0;
	}
    }
  else if (chdir(args[1]) == -1)
    {
      perror("cd");
      return 0;
    }
  return 1;
}
