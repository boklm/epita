/*
** my_tools.c for my_ftpd in .
** 
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
** 
** Started on  Fri Nov 29 18:39:06 2002 jean-yves tourtet
** Last update Fri Nov 29 18:43:09 2002 jean-yves tourtet
*/

#include <unistd.h>
#include <stdlib.h>

void		my_putchar(char c)
{
  write(0, &c, 1);
}

void		my_putstr(const char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

int		my_strcmp(char *s1, char *s2)
{
  while ((*s1 == *s2) && ((*s1 != '\0') || (*s2 != '\0')))
    {
      s1++;
      s2++;
    }
  return (*s1 - *s2);
}

int		my_strlen(const char *str)
{
  int		str_len;

  str_len = 0;
  while (*str)
    {
      str++;
      str_len++;
    }
  return str_len;
}

char		*my_strconcat(char *str1, char c)
{
  char		*result;
  int		i;

  result = malloc(my_strlen(str1) + 2);
  for (i = 0; i < my_strlen(str1); i++)
    result[i] = str1[i];
  result[my_strlen(str1)] = c;
  result[my_strlen(str1) + 1] = '\0';
  return (result);
}
