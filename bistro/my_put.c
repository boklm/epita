/*
** my_putstr.c for bistromathique in /u/a1/legros_b/c/rendu/piscine/j2
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Tue Sep 24 19:27:59 2002 bruno legros
** Last update Sun Nov 10 12:44:32 2002 bruno legros
*/

#include "bistro.h"

void	my_putchar(char c)
{
  if (write(STDOUT_FILENO, &c, 1) < 0)
    my_puterror(E_THE_WORLD_IS_OVER);
}

void	my_putstr(const char *str)
{
  int	i;

  for (i = 0; str[i] != '\0'; my_putchar(str[i++])) ;
}
