/*
** delete_end_spaces.h for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Mon Dec  9 18:57:37 2002 olivier lecornet
** Last update Mon Dec  9 19:45:35 2002 olivier lecornet
*/

#include "uses_parse.h"

void	delete_end_spaces(char *line)
{
  int	len;

  len = my_strlen(line) - 1;
  while ((is_space(line[len]) && (len > 0)))
    len--;
  line[++len] = '\0';
}
