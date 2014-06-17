/*
** inconnu_cmd.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec 11 08:35:55 2002 olivier lecornet
** Last update Thu Dec 12 13:12:06 2002 olivier lecornet
*/

#include "asm.h"

int	unknown_cmd(t_info *all, t_word **word)
{
  all->tete_error = add_error(all->tete_error, (*word)->word,
			      ERR_CMD_UNDEFINE, (*word)->line);
  *word = (*word)->next;
  return (0);
}
