/*
** check_errors.h for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Thu Dec 12 13:29:26 2002 olivier lecornet
** Last update Thu Dec 12 13:30:46 2002 olivier lecornet
*/

#ifndef CHECK_ERROR_H
# define CHECK_ERROR_H

# include "asm.h"

void	free_list_error(t_error *tete);
void    delete_ok_label(t_info *all);
int     rest_error(t_error *tete);

#endif /* CHECK_ERROR_H */
