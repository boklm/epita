/*
** my_strncmp.c for corewar in /u/a1/legros_b/c/rendu/proj/corewar/common
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 16:33:56 2002 bruno legros
** Last update Fri Dec 20 17:34:33 2002 eric augustin
*/

#include "my_strncmp.h"

int		my_strncmp(char *s1, char *s2, unsigned int n)
{
  unsigned int	counter;

  counter = 0;
  while ((counter < n) && (s1[counter] || s2[counter]))
    {
      if (s1[counter] > s2[counter])
	return 1;
      else
        if (s1[counter] < s2[counter])
	  return -1;
      counter++;
    }
  return 0;
}
