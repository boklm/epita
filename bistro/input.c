/*
** input.c for bistro in /u/a1/vigier_n/bistro/my_bistro
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Fri Nov  1 03:22:39 2002 nicolas vigier
** Last update Sat Nov  9 14:20:03 2002 bruno legros
*/

#include "bistro.h"

static char	my_getchar(void)
{
  char		res;
  int		i;

  if ((i = read(STDIN_FILENO, &res, 1)) < 0)
    my_puterror(E_THE_WORLD_IS_OVER);
  else
    if (i != 1)
      my_puterror(E_SYNTAX);
  return res;
}

static void	read_rpn_op(t_bistro *bistro)
{
  bistro->op_emp = my_getchar();
  bistro->op_ech = my_getchar();
  bistro->op_neg = my_getchar();
  bistro->op_add = my_getchar();
  bistro->op_sub = my_getchar();
  bistro->op_mul = my_getchar();
  bistro->op_div = my_getchar();
  bistro->op_divent = my_getchar();
  bistro->type = EXPR_RPN;
}

static void	read_infix_op(t_bistro *bistro)
{
  bistro->op_grp_beg = my_getchar();
  bistro->op_grp_end = my_getchar();
  bistro->op_add = my_getchar();
  bistro->op_sub = bistro->op_neg = my_getchar();
  bistro->op_mul = my_getchar();
  bistro->op_div = my_getchar();
  bistro->op_divent = my_getchar();
  bistro->op_emp = bistro->op_add;
  bistro->type = EXPR_INFIX;
}

static void	read_base(t_bistro *bistro)
{
  int		i;

  if (!(bistro->base->base = malloc(bistro->base->base_len)))
    my_puterror(E_THE_WORLD_IS_OVER);
  i = 0;
  while (i < bistro->base->base_len)
    bistro->base->base[i++] = my_getchar();
}

static void	read_expr(t_bistro *bistro)
{
  char		*str;
  int		c;
  int		str_size;

  if (!(str = malloc(SIZE)))
    my_puterror(E_THE_WORLD_IS_OVER);
  str_size = 0;
  while ((c = read(STDIN_FILENO, str + str_size, SIZE)) == SIZE)
    if (c < 0 || !(str = realloc(str, (str_size += SIZE) + SIZE)))
      my_puterror(E_THE_WORLD_IS_OVER);
  bistro->expr = str;
  bistro->expr_len = str_size + c;
  bistro->end_expr = bistro->expr + bistro->expr_len;
}

t_bistro	*read_input(void)
{
  t_bistro	*bistro;

  if (!(bistro = malloc(sizeof (t_bistro))))
    my_puterror(E_THE_WORLD_IS_OVER);
  if ((bistro->form = my_getchar() == 51))
    read_rpn_op(bistro);
  else
    read_infix_op(bistro);
  if (!(bistro->base = malloc(sizeof (t_base))))
    my_puterror(E_THE_WORLD_IS_OVER);
  if ((bistro->base->base_len = my_getchar()) < 2)
      my_puterror(E_ARITH);
  read_base(bistro);
  read_expr(bistro);
  return bistro;
}
