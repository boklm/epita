/*
** read_expr_infix.c for bistromatique in /u/a1/vigier_n/bistromathique
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Nov  6 19:05:39 2002 nicolas vigier
** Last update Sat Nov  9 19:47:05 2002 nicolas vigier
*/

#include "bistro.h"

static int	op_val(char *c, t_bistro *bistro)
{
  if (c == NULL)
    return 0;
  if (IS_MUL(*c, bistro) || IS_DIV(*c, bistro) || IS_DIVENT(*c, bistro))
    return 1;
  if (IS_ADD(*c, bistro) || IS_SUB(*c, bistro))
    return 3;
  return -1;
}

static char	*next_operator(char *str, char *end_expr, t_bistro *bistro)
{
  int		nb_par;
  char		*save_str;

  nb_par = 0;
  save_str = str;
  if (IS_GRP_BEG(*str, bistro))
    nb_par++;
  while (++str < end_expr)
    if (IS_GRP_BEG(*str, bistro))
      nb_par++;
    else if (IS_GRP_END(*str, bistro))
      {
	if (--nb_par < 0)
	  my_puterror(E_SYNTAX);
      }
    else if (!nb_par && is_op(*str, bistro) &&
	     !is_op(*(str - 1), bistro))
      return str;
  return NULL;
}

static int	nbr_len_infix(char *expr, char *end_expr, t_bistro *bistro)
{
  int		res;

  res = 0;
  while (expr < end_expr && !is_op_infix(*expr++, bistro))
    res++;
  return res;
}

static t_nbr	*read_nbr_infix(char *expr, char *end_expr, t_bistro *bistro)
{
  t_nbr		*res;

  res = alloc_nbr(bistro->base);
  if (IS_NEG(*expr, bistro))
    {
      res->negative = 1;
      expr++;
    }
  res->nbr_len = nbr_len_infix(expr, end_expr, bistro);
  res->makefree = 0;
  free(res->nbr);
  res->nbr = expr;
  return res;
}

static t_nbr	*negative(t_nbr *nbr)
{
  nbr->negative = !nbr->negative;
  return nbr;
}

static t_nbr	*read_expr_infix_rec(char *expr, char *end_expr,
				     t_bistro *bistro)
{
  char		*tmp;
  char		*max_op;

  max_op = NULL;
  tmp = expr;
  while ((tmp = next_operator(tmp, end_expr, bistro)))
    if (op_val(tmp, bistro) >= op_val(max_op, bistro))
      max_op = tmp;
  if (!max_op)
    {
      if (IS_NEG(*expr, bistro))
	return negative(read_expr_infix_rec(expr + 1, end_expr, bistro));
      if (IS_GRP_BEG(*expr, bistro))
	return read_expr_infix_rec(expr + 1, end_expr - 1, bistro);
      return read_nbr_infix(expr, end_expr, bistro);
    }
  return  make_calcul_free(read_expr_infix_rec(expr, max_op, bistro),
			   read_expr_infix_rec(max_op + 1, end_expr, bistro),
			   *max_op, bistro);
}

t_nbr	*read_expr_infix(char *expr, t_bistro *bistro)
{
  return read_expr_infix_rec(expr, expr + bistro->expr_len, bistro);
}
