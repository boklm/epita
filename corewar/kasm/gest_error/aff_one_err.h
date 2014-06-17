/*
** aff_one_err.h for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec 11 14:39:48 2002 olivier lecornet
** Last update Thu Dec 12 16:40:08 2002 olivier lecornet
*/

#ifndef AFF_ONE_ERR_H
# define   AFF_ONE_ERR_H

# include "gest_errors.h"

void	aff_one_error(t_error *p, char *pref, char *med, char *suf);
char    *my_itoa_base(int nbr, char *base, int base_size);

#endif /* AFF_ONE_ERR_H */
