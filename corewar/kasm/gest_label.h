/*
** gest_label.h for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec 11 08:32:56 2002 olivier lecornet
** Last update Sun Dec 22 20:36:11 2002 nicolas vigier
*/

#ifndef GEST_LABEL_H
# define GEST_LABEL_H

#include "asm.h"

int		test_label(t_info *all, t_word **word);
int		eval_size_prog_cur(t_cmd_list *tete);
void		actualise_before_label(t_info *all);
void		actualise_before_label_2(t_info *all);

#endif /* GEST_LABEL_H */
