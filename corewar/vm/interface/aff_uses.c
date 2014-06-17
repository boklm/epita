/*
** aff_uses.c for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sun Dec 22 13:03:29 2002 olivier lecornet
** Last update Sun Dec 22 18:35:19 2002 olivier lecornet
*/

#include "aff.h"

int	the_write(int fd, char *s, int size)
{
  int	len;

  if ((len = write(fd, s, size)) == -1)
    {
      the_write(gl_termfd, MY_NORM, strlen(MY_NORM));
      return (0);
    }
  return (len);
}

void	actual_cadre(t_vm *vm)
{
  int	error;

  setupterm(NULL, 0, &error);
  vm->env->line = tigetnum("lines");
  vm->env->col = tigetnum("cols");
}

char	*pos_curser(int x, int y)
{
  char	*s, *xs, *ys;
  int	i, j;

  s = malloc(sizeof (char) * 25);
  s[0] = '\E';
  s[1] = '[';
  if (x < 0)
    x = 0;
  if (y < 0)
    y = 0;
  xs = my_itoa_base(x, "0123456789", 10);
  ys = my_itoa_base(y, "0123456789", 10);
  for (i = 0; i < strlen(xs); i++)
    s[i + 2] = xs[i];
  s[i + 2] = ';';
  for (j = 0; j < strlen(ys); j++)
    s[j + 3 + i] = ys[j];
  s[3 + i + j] = 'H';
  s[4 + i + j] = 0;
  free(xs);
  free(ys);
  return (s);
}

void	cl_screen(void)
{
  the_write(gl_termfd, MY_CLEAR, strlen(MY_CLEAR));
}
