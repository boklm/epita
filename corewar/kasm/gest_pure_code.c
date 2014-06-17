/*
** pure_code.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Tue Dec 10 16:42:58 2002 olivier lecornet
** Last update Sun Dec 22 13:14:52 2002 nicolas vigier
*/

#include "asm.h"

int	verif_char(char *line, const char *base, int size)
{
  int	i, j;

  i = 0;
  while (line[i])
    {
      for (j = 0; (j < size) && (base[j] != line[i]); j++) ;
      if (j == size)
	return (0);
      i++;
    }
  return (1);
}

int		test_pure_code(t_info *all, t_word **word)
{
  t_word	*p;
  t_cmd_list	*cmdlist;

  all = all;
  if (!verif_char((*word)->word, "0123456789ABCDEF", 16))
    return (0);
  p = *word;
  *word = (*word)->next;
  cmdlist = init_cmdlist();
  cmdlist->pure_code = 1;
  cmdlist->cmd[0] = p;
  cmdlist->size = my_strlen(p->word);
  all->tete_cmd = add_cmdlist(all->tete_cmd, cmdlist);
  return (1);
}
