/*
** aff_actual_table.h for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sat Dec 21 17:36:00 2002 olivier lecornet
** Last update Sun Dec 22 18:19:16 2002 olivier lecornet
*/

#ifndef AFF_ACTUAL_TABLE_H
# define AFF_ACTUAL_TABLE_H

#include "aff.h"

void	actual_player_table(t_vm *vm, int player, int emp, char *mem);
int	take_master(int curs_mem, int curs_mem_dep, char *mem);
void	my_move(int x, int y);

#endif /* AFF_ACTUAL_TABLE_H */
