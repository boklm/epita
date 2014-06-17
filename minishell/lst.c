/*
** lst.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Nov 19 13:11:53 2002 nicolas vigier
** Last update Tue Nov 19 13:12:26 2002 nicolas vigier
*/

#include "minishell.h"

t_lst		*lst_add_elt(t_lst *lst, void *newptr)
{
  t_lst		*newelt;

  newelt = mmalloc(sizeof (t_lst));
  newelt->ptr = newptr;
  newelt->next = lst;
  return newelt;
}
