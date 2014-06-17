#ifndef AFF_TABLE_H
# define AFF_TABLE_H

# include "aff.h"

char	*take_scale(int scale);
void	init_player_table(t_vm *vm, int player, int emp, char *mem);
void	aff_table(t_vm *vm);
void	aff_all_table(t_vm *vm);
void	redraw_table(t_vm *vm);

#endif /* AFF_TABLE_H */
