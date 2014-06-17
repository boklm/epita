/*
** my_atoi.c for corewar in /u/a1/legros_b/c/rendu/proj/corewar/common
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 17:40:37 2002 bruno legros
** Last update Thu Dec 19 15:05:41 2002 bruno legros
*/

#include "my_atoi.h"

static int	puis(int nb, int puis)
{
  int		i;
  int		result;

  result = 1;
  for (i = 0; i < puis; i++)
    result = result * nb;
  return result;
}

unsigned int	my_atoi(char *str)
{
  unsigned int	result;
  int		i;
  int		len;

  result = 0;
  len = my_strlen(str);
  for (i = 0; str[i] != '\0'; i++)
    result += (str[i] - 48) * puis(10, len - 1 - i);
  return result;
}

int		comp_magic(unsigned char str[4], unsigned long magic)
{
  int		i;
  unsigned char	buf_magic[4];

  for (i = 0; i < 4; i++)
    {
      buf_magic[i] = magic % 256;
      magic /= 256;
    }
  for (i = 0; i < 4; i++)
    if (buf_magic[i] != str[i])
      return 0;
  return 1;
}
