/*
** write_out.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Tue Dec  3 23:56:43 2002 jean-yves tourtet
** Last update Wed Dec  4 00:45:43 2002 jean-yves tourtet
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_tools.h"

void write_stdout(char *msg)
{
  int	size;

  size = my_strlen(msg);
  if (write(1, msg, size) == -1)
    {
      perror("write");
      exit(1);
    }
}
