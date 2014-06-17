/*
** add_cmdlist.c for corewar in /u/a1/vigier_n/asm_new/asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Thu Dec 12 19:41:05 2002 nicolas vigier
** Last update Wed Dec 18 04:42:13 2002 nicolas vigier
*/

#include "../asm.h"
#include "gest_cmd.h"

t_cmd_list	*add_cmdlist(t_cmd_list *list, t_cmd_list *new)
{
  t_cmd_list	*res;

  if (!list)
    return new;
  res = list;
  while (list->next)
    list = list->next;
  list->next = new;
  return res;
}
