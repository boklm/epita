/*
** concat_expr.h for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Thu Dec 12 17:49:24 2002 olivier lecornet
** Last update Sat Dec 21 16:31:56 2002 nicolas vigier
*/

#ifndef CONCAT_EXPR_H
# define CONCAT_EXPR_H

#include "asm.h"

void   	concat_expr(t_word *tete);
int	is_op(char c);
void	conc_virg(t_word **tmp, t_word **p, int *test);

#endif /* CONCAT_EXPR_H */
