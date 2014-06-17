/*
** gest_directives.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Thu Dec  5 14:46:14 2002 olivier lecornet
** Last update Thu Dec 12 13:44:22 2002 olivier lecornet
*/

#include "asm.h"

t_directive	tab_direc[NB_DIRECTIVES] =
  {{".name", 5, take_name},
   {".comment", 8, take_comment}};

void	verif_directive(t_info *all)
{
  if (!all->name)
    all->tete_error = add_error(all->tete_error,
				TEXT_MISSING_NAME, AFF_MESS, 0);
  if (!all->comment)
    all->tete_error = add_error(all->tete_error,
				TEXT_MISSING_COMMENT, AFF_MESS, 0);
}

int	test_directive(t_info *all, t_word **word)
{
  int	i;

  if ((*word)->word[0] != '.')
    return (0);
  for (i = 0; (i < NB_DIRECTIVES) &&
	 my_strncmp((*word)->word, tab_direc[i].name,
		    tab_direc[i].size); i++) ;
  if (i < NB_DIRECTIVES)
    tab_direc[i].func(all, word);
  else
    {
      all->tete_error = add_error(all->tete_error, (*word)->word,
				  ERR_INCONNU_DIR, (*word)->line);
      *word = (*word)->next;
    }
  return (1);
}
