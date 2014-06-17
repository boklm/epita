/*
** xmalloc.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Thu Dec  5 12:49:42 2002 olivier lecornet
** Last update Thu Dec 12 13:22:13 2002 olivier lecornet
*/

#include "../asm.h"

void	*xmalloc(int n)
{
  void	*p;

  p = malloc(n);
  if (!p)
    {
      my_write(STDERR_FILENO,
	       "Malloc: Probleme d'allocation memoire.\n", 41);
      exit(1);
    }
  return (p);
}

int	my_write(int fd, char *s, int size)
{
  int	k;

  if ((k = write(fd, s, size)) == -1)
    {
      write(STDERR_FILENO, "write error\n", my_strlen("write error\n"));
      exit(1);
    }
  return (k);
}

int	my_read(int fd, char *s, int size)
{
  int	k;

  if ((k = read(fd, s, size)) == -1)
    {
      write(STDERR_FILENO, "read error\n", my_strlen("read error\n"));
      exit(1);
    }
  return (k);
}
