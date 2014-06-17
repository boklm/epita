/*
** aff_uses_mem.c for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sun Dec 22 13:02:45 2002 olivier lecornet
** Last update Sun Dec 22 14:51:34 2002 olivier lecornet
*/

#include "aff.h"

void	delete_player_table(int player, char *mem, int size)
{
  int	i;

  for (i = 0; i < size; i++)
    if ((mem[i] == player + 1) || (mem[i] == (player + 15 + 1)))
      mem[i] = 0;
}

void	init_player_table(t_vm *vm, int player, int emp, char *mem)
{
  mem[emp] = player + 15;
}

int	take_master(int curs_mem, int curs_mem_dep, char *mem)
{
  int	tab[31] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int	i, max, id_max;

  for (i = curs_mem; i < curs_mem_dep + curs_mem; i++)
    tab[mem[i]]++;
  max = 0;
  id_max = 0;
  for (i = 0; i < 31; i++)
    if (max < tab[i])
      {
	max = tab[i];
	id_max = i;
      }
  return (id_max);
}

void	aff_one_mem(int master)
{
  int	flag;

  flag = 0;
  if (master)
    {
      if ((master - 1) >= 15)
	{
	  flag = 1;
	  master = master - 15;
	}
      while (!the_write(gl_termfd, tab[master - 1].color,
		strlen(tab[master - 1].color))) ;
      if (flag)
	while (!the_write(gl_termfd, "#", 1)) ;
      else
	while (!the_write(gl_termfd, "+", 1)) ;
      while (!the_write(gl_termfd, MY_NORM, strlen(MY_NORM))) ;
    }
  else
    while (!the_write(gl_termfd, " ", 1)) ;
}
