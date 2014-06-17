/*
** gest_errors.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Thu Dec  5 13:05:31 2002 olivier lecornet
** Last update Sun Dec 22 11:41:50 2002 nicolas vigier
*/

#include "gest_errors.h"

static  t_error		*init_t_error(char *msg, int type, int line)
{
  t_error	*p;

  p = xmalloc(sizeof (t_error));
  p->type = type;
  p->msg = msg;
  p->line = line;
  p->next = NULL;
  return (p);
}

t_error		*append_t_error(t_error	*tete, t_error *node)
{
  t_error	*p;

  if (!tete)
    return (node);
  for (p = tete; p->next != NULL; p = p->next) ;
  p->next = node;
  return (tete);
}

t_error		*add_error_sorted(t_error *tete, char *msg, int type, int line)
{
  t_error	*p, *tmp;

  p = init_t_error(msg, type, line);
  if (!tete)
    return p;
  if (tete->line > line)
    {
      p->next = tete;
      return p;
    }
  for (tmp = tete; tmp->next != NULL && line < tmp->line; tmp = tmp->next)
    ;
  p->next = tmp->next;
  tmp->next = p;
  return tete;
}

t_error		*add_error(t_error *tete, char *msg, int type, int line)
{
  t_error	*p, *tmp;

  p = init_t_error(msg, type, line);
  if (!tete)
    return (p);
  for (tmp = tete; tmp->next != NULL; tmp = tmp->next) ;
  tmp->next = p;
  return (tete);
}
