/*
** gest_directives.h for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Tue Dec 10 13:05:22 2002 olivier lecornet
** Last update Thu Dec 12 13:16:54 2002 olivier lecornet
*/

#ifndef GEST_DIRECTIVES_H
# define GEST_DIRECTIVES_H

# include "asm.h"
# include "take_name.h"
# include "take_comment.h"

int	test_directive(t_info *all, t_word **word);
void	verif_directive(t_info *all);

#endif /* GEST_DIRECTIVES_H */
