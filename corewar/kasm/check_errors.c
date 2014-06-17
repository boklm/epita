/*
** check_errors.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Thu Dec 12 13:26:43 2002 olivier lecornet
** Last update Sun Dec 22 11:21:41 2002 nicolas vigier
*/

#include "asm.h"

int             rest_error(t_error *tete)
{
  t_error       *p;

  for (p = tete; p; p = p->next)
    if ((p->type != AFF_MESS) &&
	(p->type != ERR_ARG_LONG) &&
	(p->type != WAR_MULT_DIRECTIVE) &&
	(p->type != WARN_CONST_OVERFLOW) &&
	(p->type != WARN_UNUSED_LABEL))
      return (1);
  return (0);
}


void		free_list_error(t_error *tete)
{
  t_error	*error, *prec;

  for (error = tete; error; error = prec)
    {
      prec = error->next;
      if (error->msg)
	free(error->msg);
      free(error);
    }
}

void    delete_ok_label(t_info *all)
{
  t_label       *label;
  t_error       *error, *prec, *tete_del;

  tete_del = NULL;
  for (error = all->tete_error; error; prec = error, error = error->next)
    if (error->type == ERR_LABEL_UNDEFINE)
      {
        for (label = all->tete_label; label &&
               my_strcmp(label->word->word, error->msg); label = label->next) ;
        if (label)
          {
            if (prec)
              prec->next = error->next;
            else
              all->tete_error = error->next;
            error->next = NULL;
            tete_del = append_t_error(tete_del, error);
          }
      }
  free_list_error(tete_del);
}
