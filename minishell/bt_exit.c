/*
** bt_exit.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Nov 20 03:37:18 2002 nicolas vigier
** Last update Wed Nov 20 03:39:23 2002 nicolas vigier
*/

int	bt_type(void)
{
  return 1;
}

char	*bt_name(void)
{
  return "exit";
}

int	exec_bt(char **args)
{
  char	**tmp;

  tmp = args;
  exit(0);
}
