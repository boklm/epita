/*
** read_expr.c for bistro in /u/a1/vigier_n/bistro/my_bistro
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Thu Oct 31 14:39:04 2002 nicolas vigier
** Last update Sat Nov  9 11:17:21 2002 bruno legros
*/

#include "bistro.h"

static t_pile	*depil_nbr(t_nbr **nbr, t_pile *pile)
{
  t_pile	*res;

  if (!pile)
    {
      my_putstr(E_STACK);
      exit(1);
    }
  res = pile->next;
  *nbr = pile->elt;
  free(pile);
  return res;
}

static t_pile	*empil_nbr(t_nbr *nbr, t_pile *pile)
{
  t_pile	*new;

  if (!(new = malloc(sizeof (t_pile))))
    my_puterror(E_THE_WORLD_IS_OVER);
  new->elt = nbr;
  new->next = pile;
  return new;
}

static t_nbr	*make_calcul(t_nbr *nbr1, t_nbr *nbr2,
			     char op, t_bistro *bistro)
{
  t_nbr_2	*nbr;
  t_nbr		*quot;

  if (IS_MUL(op, bistro))
    return reduc(mul(nbr1, nbr2));
  if (IS_ADD(op, bistro))
    return reduc(add_sub(nbr1, nbr2));
  if (IS_SUB(op, bistro))
    return reduc(add_sub(nbr1, not(nbr2)));
  if (IS_DIV(op, bistro))
    return reduc(my_div(nbr1, nbr2));
  if (IS_DIVENT(op, bistro))
    {
      nbr = div_ent(nbr1, nbr2);
      free_nbr(nbr->rest);
      quot = nbr->quot;
      free(nbr);
      return check_zero(quot, 0);
    }
  return NULL;
}

t_nbr		*make_calcul_free(t_nbr *nbr1, t_nbr *nbr2,
				  char op, t_bistro *bistro)
{
  t_nbr		*res;

  res = make_calcul(nbr1, nbr2, op, bistro);
  free_nbr(nbr1);
  free_nbr(nbr2);
  return res;
}

static t_pile	*swap_pile(t_pile *pile)
{
  t_nbr		*tmp;
  t_nbr		*new_nbr;

  pile = depil_nbr(&new_nbr, pile);
  pile = depil_nbr(&tmp, pile);
  pile = empil_nbr(new_nbr, pile);
  pile = empil_nbr(tmp, pile);
  return pile;
}

static t_pile	*neg_piletop(t_pile *pile)
{
  t_nbr		*tmp;

  pile = depil_nbr(&tmp, pile);
  not(tmp);
  pile = empil_nbr(tmp, pile);
  return pile;
}

static t_pile	*make_calcul_full(t_pile *pile,
				  t_bistro *bistro,
				  char *expr)
{
  t_nbr		*new_nbr;
  t_nbr		*tmp;

  pile = depil_nbr(&new_nbr, pile);
  pile = depil_nbr(&tmp, pile);
  tmp = make_calcul_free(tmp, new_nbr, *expr, bistro);
  pile = empil_nbr(tmp, pile);
  return pile;
}

t_nbr		*read_expr_rpn(char *expr, t_bistro *bistro)
{
  t_nbr		*new_nbr;
  t_pile	*pile;
  t_nbr		*tmp;

  pile = NULL;
  bistro->expr_cursor = 0;
  while (bistro->expr_cursor < bistro->expr_len)
    {
      if ((new_nbr = read_nbr(&expr, bistro)))
	  pile = empil_nbr(new_nbr, pile);
      if (IS_NEG(*expr, bistro))
	pile = neg_piletop(pile);
      if (IS_ECH(*expr, bistro))
	pile = swap_pile(pile);
      if (!IS_EMP(*expr, bistro) && !IS_NEG(*expr, bistro) &&
	  !IS_ECH(*expr, bistro) &&
	  bistro->expr_cursor < bistro->expr_len)
	pile = make_calcul_full(pile, bistro, expr);
      expr++;
      bistro->expr_cursor++;
    }
  pile = depil_nbr(&tmp, pile);
  if (pile)
    error_msg(E_STACK, 1);
  return tmp;
}

void		error_msg(char *msg, int exitcode)
{
  my_putstr(msg);
  exit(exitcode);
}
