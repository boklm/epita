/*
** utils2.c for bistro in /u/a1/vigier_n/bistro/my_bistro
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Fri Nov  1 10:46:33 2002 nicolas vigier
** Last update Sat Nov  9 11:54:27 2002 nicolas vigier
*/

#include "bistro.h"

int	is_op(char c, t_bistro *bistro)
{
  return (IS_EMP(c, bistro) || IS_ECH(c, bistro) || IS_NEG(c, bistro) ||
	  IS_ADD(c, bistro) || IS_SUB(c, bistro) || IS_MUL(c, bistro) ||
	  IS_DIV(c, bistro) || IS_DIV(c, bistro) || IS_DIVENT(c, bistro));
}

int	is_op_infix(char c, t_bistro *bistro)
{
  return (is_op(c, bistro) || IS_GRP_BEG(c, bistro) || IS_GRP_END(c, bistro));
}

int	nbr_len(char *expr, int maxsize, t_bistro *bistro)
{
  int	res;

  res = 0;
  while (maxsize--)
    {
      if (is_op(*expr++, bistro))
	break ;
      res++;
    }
  return res;
}

t_nbr	*read_nbr(char **expr, t_bistro *bistro)
{
  t_nbr	*res;
  int	size_expr;

  size_expr = nbr_len(*expr, bistro->expr_len - bistro->expr_cursor, bistro);
  if (!size_expr)
    return NULL;
  res = alloc_nbr(bistro->base);
  free(res->nbr);
  res->nbr = *expr;
  res->nbr_len = size_expr;
  res->makefree = 0;
  *expr += size_expr;
  bistro->expr_cursor += size_expr;
  return res;
}
