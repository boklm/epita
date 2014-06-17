/*
** verif_syntaxe.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Tue Dec 10 12:04:06 2002 olivier lecornet
** Last update Sun Dec 22 19:29:05 2002 nicolas vigier
*/

#include "asm.h"

static void	aff_verbose(t_info *all)
{
  t_label	*p;
  t_cmd_list	*p1;

  my_putstr("\n===> Infos :\n");
  if (all->name)
    my_putstrstr("name\t= ^\n", all->name);
  if (all->comment)
    my_putstrstr("comment\t= ^\n", all->comment);
  my_putstr("\n===> Commands :\n");
  for (p1 = all->tete_cmd; p1; p1 = p1->next)
    {
      my_putstrnbr("Line ^", p1->cmd[0]->line);
      my_putstrstr(": Name = ^\n", p1->cmd[0]->word);
    }
  my_putstr("\n===> Labels :\n");
  for (p = all->tete_label; p; p = p->next)
    {
      my_putstrnbr("Line ^", p->word->line);
      my_putstrstr(": Label = ^", p->word->word);
      my_putstrnbr("Addr = ^\n", p->addr);
    }
  my_putchar('\n');
}

void	aff_parsage(t_info *all)
{
  if (all->flags & VERBOSE_MODE)
    aff_verbose(all);
  if (all->tete_error)
    {
      my_putstr("\n===> Errors / Warnings :\n");
      aff_errors(all->tete_error);
    }
}

static void	extract_word(t_info *all)
{
  char		*line;

  while ((line = getln(all)) != NULL)
    {
      (all->line)++;
      delete_comment(line);
      delete_end_spaces(line);
      if (line)
	create_list_word(all, line);
      if (line)
	free(line);
    }
  concat_expr(all->tete_words);
}

static void	check_unused_labels(t_info *all)
{
  t_label	*label;

  for (label = all->tete_label; label; label = label->next)
    if (!label->used)
      all->tete_error = add_error_sorted(all->tete_error, label->word->word,
					 WARN_UNUSED_LABEL, label->word->line);
}

static void	parse(t_info *all)
{
  t_word	*word;

  word = all->tete_words;
  while (word != NULL)
    {
      if (!test_cmd(all, &word))
	  if (!test_directive(all, &word))
	    if (!test_label(all, &word))
	      if (!test_pure_code(all, &word))
		unknown_cmd(all, &word);
    }
  actualise_before_label_2(all);
  actualise_before_label(all);
}

int		verif_syntaxe(t_info *all)
{
  extract_word(all);
  parse(all);
  verif_directive(all);
  delete_ok_label(all);
  close(all->fd_input);
  if (all->do_encode && !gest_encode(all))
    return 0;
  check_unused_labels(all);
  aff_parsage(all);
  if (rest_error(all->tete_error))
    return 0;
  return 1;
}
