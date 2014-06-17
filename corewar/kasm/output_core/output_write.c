/*
** output_write.c for corewar in /u/a1/vigier_n/corewar/corewar_asm/corewar_asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec 10 12:16:47 2002 nicolas vigier
** Last update Sun Dec 22 14:56:32 2002 nicolas vigier
*/

#include "../asm.h"
#include "output_core.h"

int	output_write(t_outputfile *output, char *filename)
{
  int	outfd;
  int	res;

  if ((outfd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
    {
      write(STDERR_FILENO, "Error openning output file ", 28);
      write(STDERR_FILENO, filename, my_strlen(filename));
      write(STDERR_FILENO, "\n", 1);
      return 0;
    }
  my_putstrnbr("File size: ^ Bytes\n", output->ptr - output->output);
  if (write(outfd, output->output, output->ptr - output->output + !output->quartet_1) ==
      output->ptr - output->output)
    res = 1;
  else
    res = 0;
  close(outfd);
  return res;
}
