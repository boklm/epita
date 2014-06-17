/*
** concat_expr.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Thu Dec 12 17:36:02 2002 olivier lecornet
** Last update Sat Dec 21 16:57:52 2002 nicolas vigier
*/

#include "asm.h"

int	is_op(char c)
{
  if ((c == '+') || (c == '-') ||
      (c == '/') || (c == '*') ||
      (c == '%'))
    return (1);
  return (0);
}

void	conc_virg(t_word **tmp, t_word **p, int *test)
{
  char	*res;

  (*tmp) = (*p)->next;
  (*p)->next = (*tmp)->next;
  res = my_strcat((*p)->word, (*tmp)->word);
  (*p)->word = res;
  if ((*p)->next == NULL)
    *test = 0;
}

void		concat_virg(t_word *tete)
{
  t_word	*p, *tmp;
  char		*res;
  int		test;

  for (p = tete; p; p = p->next)
    {
      test = 1;
      if (p->next)
	if (p->next->word[0] == ',')
	  {
	    tmp = p->next;
	    p->next = tmp->next;
	    res = my_strcat(p->word, tmp->word);
	    p->word = res;
	  }
    }
}

static int	not_closed(char *str)
{
  int		i;
  int		len;

  len = my_strlen(str);
  for (i = 1; i < len; i++)
    if (str[i] == ']')
      return 0;
  return 1;
}

void	concat_add(t_word *tete)
{
  t_word	*p, *tmp;
  char		*res;

  for (p = tete; p; p = p->next)
    {
      if ((p->word[0] == '[') && p->next &&
	  (not_closed(p->word)))
	{
	  res = my_strcat(p->word, p->next->word);
	  free(p->word);
	  tmp = p->next;
	  p->next = p->next->next;
	  p->word = res;
	  free(tmp->word);
	  free(tmp);
	}
      if (p->next)
	if ((p->word[0] == '[') && (p->next->word[0] == ']'))
	  {
	    res = my_strcat(p->word, p->next->word);
	    free(p->word);
	    tmp = p->next;
	    p->word = res;
	    p->next = p->next->next;
	    free(tmp->word);
	    free(tmp);
	  }
    }
}

void	concat_expr(t_word *tete)
{
  concat_virg(tete);
  concat_add(tete);
}
