/*
** echo.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Nov 19 13:43:27 2002 nicolas vigier
** Last update Wed Nov 20 03:36:19 2002 nicolas vigier
*/

#include <unistd.h>
#include "my_strlen.c"

int	bt_type(void)
{
  return 0;
}

char	*bt_name(void)
{
  return "echo";
}

int	exec_bt(char **args)
{
  int	i;
  int	size;

  i = 1;
  while (args[i])
    {
      size = my_strlen(args[i]);
      write(STDOUT_FILENO, args[i], size);
      i++;
    }
  write(STDOUT_FILENO, "\n", 1);
  return 0;
}
