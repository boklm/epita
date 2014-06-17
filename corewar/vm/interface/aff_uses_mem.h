/*
** aff_uses_mem.h for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sun Dec 22 13:02:45 2002 olivier lecornet
** Last update Sun Dec 22 14:34:20 2002 olivier lecornet
*/

#ifndef AFF_USES_MEM_H
# define AFF_USES_MEM_H

#include "aff.h"

void	reaf_table(t_vm *vm);
void	actual_player_table(t_vm *vm, int player, int emp, char *mem);
void	delete_player_table(int player, char *mem, int size);
void	init_player_table(t_vm *vm, int player, int emp, char *mem);
void	aff_one_mem(int master);

#endif /* AFF_USES_MEM_H */
