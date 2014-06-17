/*
** create_list_word.c for ] in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Tue Dec 10 12:05:09 2002 olivier lecornet
** Last update Sat Dec 21 18:26:07 2002 nicolas vigier
*/

#include "asm.h"

t_word		*init_t_word(char *name, int line)
{
  t_word	*p;

  p = xmalloc(sizeof (t_word));
  p->word = name;
  p->line = line;
  p->next = NULL;
  return (p);
}

static t_word	*append_t_word(t_word *tete, t_word *node)
{
  t_word	*p;

  if (!tete)
    return (node);
  for (p = tete; p->next; p = p->next) ;
  p->next = node;
  return (tete);
}

void		create_list_word(t_info *all, char *line)
{
  char		*pos, *name;
  t_word	*p;
  int		num_line;

  pos = line;
  while (pos)
    {
      num_line = all->line;
      pos = next_word(pos);
      if (pos)
	{
	  name = isolate_word(all, &pos);
	  p = init_t_word(name, num_line);
	  all->tete_words = append_t_word(all->tete_words, p);
	}
    }
}
