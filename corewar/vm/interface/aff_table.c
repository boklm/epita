/*
** aff_table.c for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sat Dec 21 17:22:00 2002 olivier lecornet
** Last update Sun Dec 22 19:49:27 2002 olivier lecornet
*/

#include "aff.h"

char	*take_scale(int scale)
{
  char	*res, *str_scale;
  int	len, i;

  res = my_malloc(10 * sizeof (char));
  if ((scale == 0) || (scale == 1))
    {
      res[0] = '1';
      res[1] = 0;
    }
  else
    {
      res[0] = '1';
      res[1] = '/';
      str_scale = my_itoa_base(scale, "0123456789", 10);
      len = strlen(str_scale);
      for (i = 0; i < len; i++)
	res[i + 2] = str_scale[i];
      free(str_scale);
      res[i + 2] = 0;
    }
  return (res);
}

void	redraw_table(t_vm *vm)
{
  int   i, j, curs_mem, curs_mem_dep, master;

  curs_mem = 0;
  for (i = 1; i < vm->env->line - 5; i++)
    {
      my_move(6 + i, 4);
      for (j = 1; j < vm->env->col - 30; j++)
	{
	  if (curs_mem <= vm->size)
	    {
	      for (curs_mem_dep = 0; (curs_mem_dep < vm->env->scale) &&
		     (curs_mem_dep + curs_mem < vm->size); curs_mem_dep++) ;
	      master = take_master(curs_mem, curs_mem_dep + 1, vm->env->mem);
	      if (master)
		aff_one_mem(master);
	      else
		the_write(gl_termfd, " ", 1);
	    }
	  curs_mem += curs_mem_dep + 1;
	}
    }
}

void	aff_table(t_vm *vm)
{
  int   i, j, curs_mem, curs_mem_dep, master;
  char	t[1];

  curs_mem = 0;
  for (i = 1; i < (vm->env->line - 10); i++)
    {
      my_move(6 + i, 4);
      for (j = 1; j < vm->env->col - 30; j++)
	{
	  if (curs_mem < vm->size)
	    {
	      for (curs_mem_dep = 0; (curs_mem_dep < vm->env->scale) &&
		     (curs_mem_dep + curs_mem < vm->size);
		   curs_mem_dep++) ;
	      master = take_master(curs_mem, curs_mem_dep + 1, vm->env->mem);
	      aff_one_mem(master);
	    }
	  else
	    the_write(gl_termfd, "-", 1);
	  curs_mem += curs_mem_dep + 1;
	}
    }
}

void	aff_all_table(t_vm *vm)
{
  int	surface;
  char	*str_scale;

  surface = (vm->env->col - 30) * (vm->env->line - 10);
  if (surface == 0)
    surface = 1;
  vm->env->scale = vm->size / surface;
  if ((surface * vm->env->scale) > vm->size)
    vm->env->scale--;
  str_scale = take_scale(vm->env->scale);
  the_write(gl_termfd, str_scale, strlen(str_scale));
  the_write(gl_termfd, ")", 1);
  aff_table(vm);
}
