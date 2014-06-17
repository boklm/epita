/*
** my_write.c for corewar in /u/a1/legros_b/c/rendu/proj/corewar/common
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 17:21:46 2002 bruno legros
** Last update Wed Dec 11 17:33:03 2002 bruno legros
*/

#include "my_write.h"

void	my_write(int file, char *str, int size)
{
  if (write(file, str, size) < 0)
    exit(1);
}
