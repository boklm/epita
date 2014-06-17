/*
** take_name.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Tue Dec 10 13:12:31 2002 olivier lecornet
** Last update Thu Dec 12 17:29:52 2002 olivier lecornet
*/

#include "asm.h"

void	valid_name_format(t_info *all, t_word **word)
{
  char	*name, *tmp;
  int	i, len;

  if (all->name)
    {
      free(all->name);
      all->tete_error = add_error(all->tete_error, ".name",
				  WAR_MULT_DIRECTIVE, (*word)->line);
    }
  name = xmalloc(PROG_NAME_LENGTH * sizeof (char) + 1);
  len = my_strlen((*word)->word) - 2;
  if (len > PROG_NAME_LENGTH)
    all->tete_error = add_error(all->tete_error, ".name",
				ERR_ARG_LONG, (*word)->line);
  tmp = &((*word)->word[1]);
  len = my_strlen(tmp);
  for (i = 0; (i < (len - 1)) && (i < PROG_NAME_LENGTH); i++)
    name[i] = tmp[i];
  while (i < PROG_NAME_LENGTH)
    name[i++] = 0;
  name[i] = 0;
  free((*word)->word);
  all->name = name;
}

void	bad_name_format(t_info *all, t_word **word)
{
  all->tete_error = add_error(all->tete_error, ".name",
			      ERR_FORMAT_ARG, (*word)->line);
  *word = (*word)->next;
}

void		take_name(t_info *all, t_word **word)
{
  t_word	*p;
  int		line;

  line = (*word)->line;
  *word = (*word)->next;
  if (*word)
    if (((*word)->word[0] == '\"') &&
	((*word)->word[my_strlen((*word)->word) - 1] == '\"'))
      {
	valid_name_format(all, word);
	p = (*word)->next;
	free(*word);
	*word = p;
      }
    else
      bad_name_format(all, word);
  else
    all->tete_error = add_error(all->tete_error, ".name",
				ERR_MISS_ARG_DIR, line);
}
