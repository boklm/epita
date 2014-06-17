/*
** my_error.c for corewar in /u/a1/legros_b/c/rendu/proj/corewar
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 14:47:45 2002 bruno legros
** Last update Sat Dec 21 18:07:03 2002 eric augustin
*/

#include "my_error.h"

void	my_error(char *s, char *str, char *s3, int ex)
{
  if (write(STDERR_FILENO, s, my_strlen(s)) < 0)
    exit(1);
  if (write(STDERR_FILENO, str, my_strlen(str)) < 0)
    exit(1);
  if (s3)
    if (write(STDERR_FILENO, s3, my_strlen(s3)) < 0)
      exit(1);
  if (write(STDERR_FILENO, "\n", 1) < 0)
    exit(1);
  if (ex)
    exit(ex);
}

void	*my_malloc(size_t size)
{
  void	*res;

  if (!(res = malloc(size)))
    my_error("", "*** Error malloc", NULL, 1);
  return res;
}
