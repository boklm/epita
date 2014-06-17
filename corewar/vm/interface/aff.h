/*
** aff.h for  in /u/a1/lecorn_o/c/corewar/vm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Sat Dec 21 17:21:04 2002 olivier lecornet
** Last update Sun Dec 22 18:50:43 2002 olivier lecornet
*/

#ifndef AFF_H
# define AFF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>

# include "aff_macro.h"
# include "../vm.h"

# include "aff_uses.h"
# include "aff_uses_mem.h"
# include "aff_init.h"
# include "aff_cadre.h"
# include "aff_info_player.h"
# include "aff_actual_table.h"
# include "gest_signaux.h"
# include "aff_result.h"

void	*my_malloc(size_t size);

extern int		gl_termfd;
extern t_aff_player	tab[MAX_NB_PLAYER];

#endif /* AFF_H */
