/*
** next_word.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Mon Dec  9 18:51:11 2002 olivier lecornet
** Last update Mon Dec  9 19:45:47 2002 olivier lecornet
*/

#include "uses_parse.h"

char	*next_word(char *line)
{
  int	i;

  i = 0;
  while ((line[i] == '\t') || (line[i] == ' '))
    i++;
  if (line[i] == '\0')
    return (NULL);
  return (&(line[i]));
}
