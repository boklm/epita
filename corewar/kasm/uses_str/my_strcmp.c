/*
** my_strcmp.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Wed Dec 11 10:58:57 2002 olivier lecornet
** Last update Wed Dec 11 11:09:19 2002 olivier lecornet
*/

#include "uses_str.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i, len1, len2;

  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  for (i = 0; (i < len1) && (i < len2) && (s1[i] == s2[i]); i++) ;
  return (s1[i] - s2[i]);
}
