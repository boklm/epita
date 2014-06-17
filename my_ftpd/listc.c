/*
** listc.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 08:02:18 2002 nicolas vigier
** Last update Tue Dec  3 08:36:26 2002 nicolas vigier
*/

#include <stdlib.h>
#include "listc.h"
#include "utils.h"

t_listc		*listc_append(t_listc *list, void *new_val)
{
  t_listc	*tmplist;
  t_listc	*new_list;

  new_list = xmalloc (sizeof (t_listc));
  new_list->data = new_val;
  new_list->next = NULL;
  if (!list)
    {
      new_list->prev = NULL;
      return new_list;
    }
  tmplist = list;
  while (tmplist->next)
    tmplist = tmplist->next;
  new_list->prev = tmplist;
  tmplist->next = new_list;
  return list;
}

t_listc		*listc_preppend(t_listc *list, void *new_val)
{
  t_listc	*new_list;

  new_list = xmalloc (sizeof (t_listc));
  new_list->data = new_val;
  new_list->prev = NULL;
  new_list->next = list;
  if (list)
    list->prev = new_list;
  return new_list;
}
