/*
** main.c for bistromathique in /u/a1/vigier_n/bistro/my_bistro
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Fri Nov  1 11:38:43 2002 nicolas vigier
** Last update Sat Nov  9 11:59:36 2002 nicolas vigier
*/

#include "bistro.h"

int		main(void)
{
  t_bistro	*bistro;
  t_nbr		*res;

  bistro = read_input();
  if (bistro->type == EXPR_RPN)
    {
      res = read_expr_rpn(bistro->expr, bistro);
      output_nbr(res, bistro);
    }
  else
    {
      res = read_expr_infix(bistro->expr, bistro);
      output_nbr_infix(res, bistro);
    }
  free(bistro->expr);
  return 0;
}
