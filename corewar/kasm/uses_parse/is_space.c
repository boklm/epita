/*
** is_space.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Mon Dec  9 18:52:34 2002 olivier lecornet
** Last update Mon Dec  9 19:46:05 2002 olivier lecornet
*/

#include "uses_parse.h"

int	is_space(char c)
{
  if (c == '\0')
    return (1);
  if ((c == '\t') || (c == ' '))
    return (2);
  return (0);
}
