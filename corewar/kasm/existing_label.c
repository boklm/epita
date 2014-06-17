/*
** existing_label.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Wed Dec 11 11:51:28 2002 olivier lecornet
** Last update Wed Dec 11 11:51:48 2002 olivier lecornet
*/

#include "asm.h"

int		existing_label(t_label *tete, char *label)
{
  t_label	*p;

  for (p = tete; p && (my_strcmp(p->word->word, label)); p = p->next) ;
  if (p)
    return (1);
  return (0);
}
