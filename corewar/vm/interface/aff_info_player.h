/*
** aff_info_player.h for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sat Dec 21 17:21:31 2002 olivier lecornet
** Last update Sun Dec 22 13:06:54 2002 olivier lecornet
*/

#ifndef AFF_INFO_PLAYER_H
# define AFF_INFO_PLAYER_H

# include "aff.h"

void	init_info_player(int nb_proc[MAX_NB_PLAYER], t_proc *tete);
int	aff_info_player(t_vm *vm);
char    *my_itoa_base(int nbr, char *base, int base_size);

#endif /* AFF_INFO_PLAYER_H */
