/*
** take_comment.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Tue Dec 10 13:10:44 2002 olivier lecornet
** Last update Sat Dec 21 09:58:56 2002 nicolas vigier
*/

#include "asm.h"

void	valid_comment_format(t_info *all, t_word **word)
{
  char	*comment;
  int	i, len;

  if (all->comment)
    {
      free(all->comment);
      all->tete_error = add_error(all->tete_error, ".comment",
				  WAR_MULT_DIRECTIVE, (*word)->line);
    }
  comment = xmalloc(PROG_COMMENT_LENGTH * sizeof (char) + 1);
  len = my_strlen((*word)->word) - 1;
  if (len > PROG_COMMENT_LENGTH)
    all->tete_error = add_error(all->tete_error, ".comment",
				ERR_ARG_LONG, (*word)->line);
  for (i = 1; (i < len) && (i < PROG_COMMENT_LENGTH + 1); i++)
    comment[i - 1] = (*word)->word[i];
  while (i < PROG_COMMENT_LENGTH + 2)
    comment[i++ - 1] = 0;
  free((*word)->word);
  all->comment = comment;
}

void	bad_comment_format(t_info *all, t_word **word)
{
  all->tete_error = add_error(all->tete_error, ".comment",
			      ERR_FORMAT_ARG, (*word)->line);
  *word = (*word)->next;
}

void		take_comment(t_info *all, t_word **word)
{
  t_word       	*p;
  int	       	line;

  line = (*word)->line;
  *word = (*word)->next;
  if (*word)
    if (((*word)->word[0] == '\"') &&
	((*word)->word[my_strlen((*word)->word) - 1] == '\"'))
      {
	valid_comment_format(all, word);
	p = (*word)->next;
	free(*word);
	*word = p;
      }
    else
      bad_comment_format(all, word);
  else
    all->tete_error = add_error(all->tete_error, ".comment",
				ERR_MISS_ARG_DIR, line);
}
