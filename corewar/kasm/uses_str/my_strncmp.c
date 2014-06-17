/*
** my_strncmp.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Mon Dec  9 15:20:26 2002 olivier lecornet
** Last update Mon Dec  9 19:04:47 2002 olivier lecornet
*/

#include "uses_str.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  if (!s1 || !s2)
    return (1);
  for (i = 0; s1[i] && s2[i] && (s1[i] == s2[i]) && (i < n); i++) ;
  if (i == n)
    return (0);
  return (s1[i] - s2[i]);
}
