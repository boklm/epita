/*
** gest_label.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Tue Dec 10 17:04:58 2002 olivier lecornet
** Last update Sun Dec 22 20:36:22 2002 nicolas vigier
*/

#include "asm.h"

void			err_ambigous_label(t_info *all, char *res, int line);
static void		add_label_multi(t_info *all, char *res, int line, int flag);

static t_label		*alloc_t_label(void)
{
  t_label		*p;

  p = xmalloc(sizeof (t_label));
  p->word = NULL;
  p->addr = 0;
  p->next = NULL;
  p->used = 0;
  p->type = 0;
  return (p);
}

int		eval_size_prog_cur(t_cmd_list *tete)
{
  int		res;
  t_cmd_list	*p;

  res = 0;
  for (p = tete; p; p = p->next)
    res += p->size;
  return (res);
}

static t_label		*append_t_label(t_label *tete, t_label *node)
{
  t_label		*p;

  if (!tete)
    return (node);
  for (p = tete; p->next; p = p->next) ;
  p->next = node;
  return (tete);
}

static int	is_valid_label(char *label)
{
  int		i, len;
  char		base[10] = "0123456789";

  len = my_strlen(label);
  for (i = 0; (i < 10) && (base[i] != label[0]); i++) ;
  if (i < 10)
    return (0);
  for (i = 0; (i < (len)); i++)
    if (!((('0' <= label[i]) && (label[i] <= '9')) ||
	  (('A' <= label[i]) && (label[i] <= 'Z')) ||
	  (('a' <= label[i]) && (label[i] <= 'z')) ||
	  (label[i] == '_')))
      return (0);
  return (1);
}

static int	is_before_label(t_info *all, t_word *word)
{
  char		*res;
  t_label	*label;

  if (word->word[0] != ':')
    return (0);
  res = my_strdup(&(word->word[1]));
  if (is_valid_label(res))
    if (!existing_label(all->tete_label, res))
      {
	label = alloc_t_label();
	label->addr = eval_size_prog_cur(all->tete_cmd);
	free(word->word);
	word->word = res;
	label->word = word;
	label->type = 1;
	all->tete_label = append_t_label(all->tete_label, label);
      }
    else
      all->tete_error = add_error(all->tete_error, res,
				  ERR_MULT_LABEL_DEF, word->line);
  else
    err_ambigous_label(all, res, word->line);
  return (1);
}

void	actualise_before_label_2(t_info *all)
{
  t_label	*p;

  for (p = all->tete_label; p; p = p->next)
    if (p->type == 1)
	p->type = 2;
}

void	actualise_before_label(t_info *all)
{
  t_label	*p;

  for (p = all->tete_label; p; p = p->next)
    if (p->type == 2)
      {
	p->addr = eval_size_prog_cur(all->tete_cmd);
	p->type = 0;
      }
}

void	err_ambigous_label(t_info *all, char *res, int line)
{
  int	i, len;

  len = my_strlen(res);
  for (i = 0; (i < len) && (res[i] != ':'); i++) ;
  if (res[i] == ':')
    {
	  res[i] = 0;
	  if (is_valid_label(res))
	    all->tete_error = add_error(all->tete_error, res,
					ERR_AMBIGOUS_LABEL, line);
	  else
	    all->tete_error = add_error(all->tete_error, res,
					ERR_BAD_NAME_LABEL, line);
	  if ((i + 1) < len)
	    add_label_multi(all, my_strdup(&(res[i + 1])), line, 1);
    }
  else
    all->tete_error = add_error(all->tete_error, res,
				ERR_BAD_NAME_LABEL, line);
}

static void	add_label_multi(t_info *all, char *res, int line, int flag)
{
  t_word	*word;
  t_label	*label;

  if (is_valid_label(res))
    if (!existing_label(all->tete_label, res))
      {
	word = init_t_word(res, line);
	label = alloc_t_label();
	label->addr = eval_size_prog_cur(all->tete_cmd);
	label->word = word;
	if (flag)
	  label->type = 1;
	all->tete_label = append_t_label(all->tete_label, label);
      }
    else
      all->tete_error = add_error(all->tete_error, res,
				  ERR_MULT_LABEL_DEF, word->line);
  else
    err_ambigous_label(all, res, line);
}

static int	is_double_label(t_info *all, t_word *word)
{
  int		i, len;
  char		*res1, *res2;

  len = my_strlen(word->word);
  for (i = 1; (i < len - 2) && (word->word[i] != ':'); i++) ;
  if (word->word[i] != ':')
    return (0);
  word->word[i] = 0;
  res1 = my_strdup(word->word);
  res2 = my_strdup(&(word->word[i + 1]));
  add_label_multi(all, res1, word->line, 0);
  add_label_multi(all, res2, word->line, 1);
  return (1);
}

int		is_normal_label(t_info *all, t_word *word)
{
  int		len;
  t_label	*label;

  len = my_strlen(word->word);
  if (word->word[len - 1] != ':')
    return (0);
  word->word[len - 1] = 0;
  if (is_valid_label(word->word))
    if (!existing_label(all->tete_label, word->word))
      {
	label = alloc_t_label();
	label->addr = eval_size_prog_cur(all->tete_cmd);
	label->word = word;
	all->tete_label = append_t_label(all->tete_label, label);
      }
    else
      all->tete_error = add_error(all->tete_error, word->word,
				  ERR_MULT_LABEL_DEF, word->line);
  else
    all->tete_error = add_error(all->tete_error, word->word,
				ERR_BAD_NAME_LABEL, word->line);
  return (1);
}

int		test_label(t_info *all, t_word **word)
{
  if (!is_before_label(all, *word))
    if (!is_double_label(all, *word))
      if (!is_normal_label(all, *word))
	return (0);
  *word = (*word)->next;
  return (1);
}
