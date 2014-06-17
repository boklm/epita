/*
** recup_constante.c for corewar in /u/a1/vigier_n/asm_new
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Dec 18 03:52:12 2002 nicolas vigier
** Last update Sun Dec 22 20:00:17 2002 nicolas vigier
*/

#include "../asm.h"
#include "gest_encode.h"

static int		read_label(t_info *info, t_word *word, char **ptr)
{
  char			*tmp;
  int			size;
  t_label		*label;

  tmp = *ptr;
  size = 0;
  label = info->tete_label;
  while (**ptr && **ptr != ',' && **ptr != '+' && **ptr != '-')
    {
      (*ptr)++;
      size++;
    }
  while (label)
    {
      if (my_strlen(label->word->word) == size &&
	  !my_strncmp(label->word->word, tmp, size))
	{
	  label->used = 1;
	  return label->addr;
	}
      label = label->next;
    }
  info->tete_error = add_error(info->tete_error, word->word, ERR_UNKNOWN_LABEL, word->line);
  return 0;
}

static int		return_zero(t_info *info, t_word *word, char c, int *error)
{
  char			zero;

  if ((c >= 'A' && c <= 'F'))
    zero = 'A' - 10;
  else if ((c >= 'a' && c <= 'f'))
    zero = 'a' - 10;
  else
    {
      *error = 1;
      info->tete_error = add_error(info->tete_error, word->word, ERR_EXPR_CSNT, word->line);
    }
  return zero;
}

static int		return_base(char **ptr)
{
  int			base;

  base = 10;
  if (**ptr == '0')
    {
      (*ptr)++;
      if (**ptr == 'x')
	{
	  (*ptr)++;
	  base = 16;
	}
      else
	base = 8;
    }
  return base;
}

static int		read_nbr(t_info *info, t_word *word, char **ptr)
{
  int			error, res, sign;
  int			base;
  char			zero;

  error = 0;
  res = 0;
  sign = 1;
  if (**ptr == '-')
    {
      sign = -1;
      (*ptr)++;
    }
  base = return_base(ptr);
  while (**ptr && **ptr != ',' && **ptr != '+' && **ptr != '-'
	 && **ptr != '*' && **ptr != '/')
    {
      if (!my_isdigit(**ptr) && !error)
	zero = return_zero(info, word, **ptr, &error);
      else
	zero = '0';
      res *= base;
      res += **ptr - zero;
      (*ptr)++;
    }
  return sign * res;
}

static int		eval_expr(t_info *info, t_word *word)
{
  char		*tmp;
  int		res;
  int		nbr;
  char		operator;

  tmp = word->word;
  res = 0;
  operator = '+';
  while (operator && operator != ',')
    {
      nbr = (my_isdigit(*tmp) || *tmp == '-') ? read_nbr(info, word, &tmp) : read_label(info, word, &tmp);
      if (operator == '-')
	res -= nbr;
      else if (operator == '*')
	res *= nbr;
      else if (operator == '/')
	{
	  if (!nbr)
	    {
	      info->tete_error = add_error(info->tete_error, word->word, ERR_CSTE_DIV_0, word->line);
	      return 0;
	    }
	  res /= nbr;
	}
      else
	res += nbr;
      operator = *tmp++;
    }
  return res;
}

int		recup_constante(t_info *info, t_cmd_list *cmdlist, t_word *word, int size)
{
  t_cmd_list	*tmpcmdlist;
  int		expr_val;

  tmpcmdlist = cmdlist;
  expr_val = eval_expr(info, word);
  word->size = size;
  word->codage = xmalloc(size);
  while (size)
    {
      word->codage[word->size - size] = invert_quartet(expr_val);
      expr_val >>= 4;
      size--;
    }
  if (expr_val > 0)
    info->tete_error = add_error(info->tete_error, word->word, WARN_CONST_OVERFLOW,
				 word->line);
  return 1;
}
