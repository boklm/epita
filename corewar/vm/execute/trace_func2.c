/*
** trace_func2.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:51:27 2002 eric augustin
** Last update Sun Dec 22 15:51:28 2002 eric augustin
*/
#include <stdlib.h>
#include <unistd.h>
#include "trace.h"
#include "../common/my_itoa.h"
#include "../common/my_strlen.h"

void    tr5(t_func_arg *arg)
{
  char  *str;

  write(STDOUT_FILENO, " r", 2);
  str = my_itoa(arg->rx - 1);
  write(STDOUT_FILENO, str, my_strlen(str));
  free(str);
  write(STDOUT_FILENO, ", [r", 4);
  str = my_itoa(arg->ry - 1);
  write(STDOUT_FILENO, str, my_strlen(str));
  free(str);
  write(STDOUT_FILENO, "]\n", 2);
}

void	tr6(t_func_arg *arg)
{
  char	*str;

  write(STDOUT_FILENO, " [r", 3);
  str = my_itoa(arg->rx - 1);
  write(STDOUT_FILENO, str, my_strlen(str));
  free(str);
  write(STDOUT_FILENO, "], r", 4);
  str = my_itoa(arg->ry - 1);
  write(STDOUT_FILENO, str, my_strlen(str));
  free(str);
  write(STDOUT_FILENO, "\n", 1);
}
