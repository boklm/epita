/*
** output_init.c for corewar in /u/a1/vigier_n/corewar/corewar_asm/corewar_asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec 10 12:11:45 2002 nicolas vigier
** Last update Fri Dec 20 04:21:53 2002 nicolas vigier
*/

#include <stdlib.h>
#include "../asm.h"

t_outputfile	*output_init(void)
{
  t_outputfile	*res;

  res = malloc(sizeof (t_outputfile));
  res->quartet_1 = 1;
  res->output = malloc(ALLOC_SIZE);
  res->ptr = res->output;
  res->allocated = ALLOC_SIZE;
  return res;
}
