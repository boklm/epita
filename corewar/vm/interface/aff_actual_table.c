/*
** aff_actual_table.c for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sat Dec 21 17:26:06 2002 olivier lecornet
** Last update Sun Dec 22 19:28:54 2002 olivier lecornet
*/

#include "aff.h"

void	my_move(int x, int y)
{
  char	*res1;

  res1 = pos_curser(x, y);
  while (!my_write(gl_termfd, res1, strlen(res1))) ;
  free(res1);
}

void	reaf_table(t_vm *vm)
{
  int   i, j, curs_mem, curs_mem_dep, master;

  curs_mem = 0;
  for (i = 1; i < vm->env->line - 11; i++)
    {
      for (j = 1; j < vm->env->col - 30; j++)
	{
	  if (curs_mem < vm->size)
	    {
	      for (curs_mem_dep = 0; (curs_mem_dep < vm->env->scale) &&
		     (curs_mem_dep + curs_mem < vm->size); curs_mem_dep++) ;
	      master = take_master(curs_mem, curs_mem_dep + 1, vm->env->mem);
	      if (master)
		{
		  my_move(6 + i, j + 3);
		  aff_one_mem(master);
		}
	    }
	  curs_mem += curs_mem_dep + 1;
	}
    }
}

void	actual_player_table(t_vm *vm, int player, int emp, char *mem)
{
  int	deb_mem, i, size_line, col, line;

  mem[emp] = player;
  reaf_table(vm);
}
