/*
** output_core.c for corewar in /u/a1/vigier_n/corewar/corewar_asm/corewar_asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec 10 11:56:08 2002 nicolas vigier
** Last update Sat Dec 21 10:30:43 2002 nicolas vigier
*/

#include <stdlib.h>
#include "../asm.h"

static int	output_realloc(t_outputfile *output)
{
  char		*newstr;
  int		i;

  if (!(newstr = malloc(output->allocated + ALLOC_SIZE)))
    return 0;
  for (i = 0; i < output->allocated; i++)
    newstr[i] = output->output[i];
  free(output->output);
  output->output = newstr;
  output->ptr = output->output + output->allocated;
  output->allocated += ALLOC_SIZE;
  return 1;
}

int	output_char(t_outputfile *output, char elt)
{
  if (output->ptr >= output->output + output->allocated)
    if (!output_realloc(output))
      return 0;
  if (output->quartet_1)
    {
      *output->ptr = elt * 16;
      output->quartet_1 = 0;
    }
  else
    {
      *output->ptr = *output->ptr | (elt & 0x0f);
      output->quartet_1 = 1;
      output->ptr++;
    }
  return 1;
}
