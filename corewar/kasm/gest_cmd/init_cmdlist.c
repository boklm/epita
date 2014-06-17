/*
** init_cmdlist.c for corewar in /u/a1/vigier_n/asm_new/asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Thu Dec 12 19:37:45 2002 nicolas vigier
** Last update Sat Dec 21 12:04:43 2002 nicolas vigier
*/

#include "../uses_str/my_system.h"
#include "gest_cmd.h"

t_cmd_list	*init_cmdlist(void)
{
  t_cmd_list	*res;
  int		i;

  res = xmalloc(sizeof (t_cmd_list));
  res->number = 0;
  res->next = NULL;
  res->pure_code = 0;
  for (i = 0; i < 4; i++)
    res->cmd[i] = NULL;
  return res;
}
