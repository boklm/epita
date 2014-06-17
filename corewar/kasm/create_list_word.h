/*
** create_list_word.h for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Tue Dec 10 12:06:38 2002 olivier lecornet
** Last update Sat Dec 21 18:26:20 2002 nicolas vigier
*/

#ifndef CREATE_LIST_WORD_H
# define CREATE_LIST_WORD_H

#include "asm.h"

void   	create_list_word(t_info *all, char *line);

t_word		*init_t_word(char *name, int line);

#endif /* CREATE_LIST_WORD_H */
