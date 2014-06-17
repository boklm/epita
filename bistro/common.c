/*
** common.c for bistromathique in /u/a1/legros_b/c/rendu/proj/bistromathique
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Oct 30 12:37:51 2002 bruno legros
** Last update Sun Nov 10 00:26:17 2002 bruno legros
*/

#include "bistro.h"

t_nbr	*not(t_nbr *n)
{
  n->negative = !n->negative;
  return n;
}

int	bas(char c, t_base *base)
{
  int	i;

  for (i = 0; i < base->base_len && base->base[i] != c; i++) ;
  if (i < base->base_len)
    return i;
  my_putstr(E_SYNTAX);
  exit(1);
  return -1;
}

int	nbr_cmp(t_nbr *n1, t_nbr *n2, int frac)
{
  int	i;
  int	len1, len2;
  char	*nbr1, *nbr2;

  check_zero(n1, frac);
  check_zero(n2, frac);
  nbr1 = frac ? n1->frac : n1->nbr;
  len1 = frac ? n1->frac_len : n1->nbr_len;
  nbr2 = frac ? n2->frac : n2->nbr;
  len2 = frac ? n2->frac_len : n2->nbr_len;
  if (len1 > len2)
    return 1;
  if (len1 < len2)
    return -1;
  for (i = 0; i < len1; i++)
    if (bas(nbr1[i], n1->base) > bas(nbr2[i], n2->base))
      return 1;
    else
      if (bas(nbr2[i], n2->base) > bas(nbr1[i], n1->base))
	return -1;
  return 0;
}

static void	m_denom2(t_nbr *n1, t_nbr *n2)
{
  t_mul		nb1, nb2;
  t_nbr		*temp;

  nb1.nbr = n2->nbr;
  nb1.nbr_len = n2->nbr_len;
  nb2.nbr = n1->frac;
  nb2.nbr_len = n1->frac_len;
  temp = mul_temp(&nb1, &nb2, n1->base);
  if (n2->makefree)
    free(n2->nbr);
  n2->nbr = temp->nbr;
  n2->nbr_len = temp->nbr_len;
  free(temp->frac);
  free(temp);
  nb1.nbr = n1->frac;
  nb1.nbr_len = n1->frac_len;
  nb2.nbr = n2->frac;
  nb2.nbr_len = n2->frac_len;
  temp = mul_temp(&nb1, &nb2, n1->base);
  free(n1->frac);
  if (!(n2->frac = malloc(n2->frac_len = temp->nbr_len)))
    my_puterror(E_THE_WORLD_IS_OVER);
  n1->frac = temp->nbr;
  my_strncpy(n2->frac, temp->nbr, n1->frac_len = temp->nbr_len);
  free(temp->frac);
  free(temp);
}

void	m_denom(t_nbr *n1, t_nbr *n2)
{
  t_mul	nb1, nb2;
  t_nbr	*temp;

  if (nbr_cmp(n1, n2, 1))
    {
      nb1.nbr = n1->nbr;
      nb1.nbr_len = n1->nbr_len;
      nb2.nbr = n2->frac;
      nb2.nbr_len = n2->frac_len;
      temp = mul_temp(&nb1, &nb2, n1->base);
      if (n1->makefree)
	free(n1->nbr);
      n1->nbr = temp->nbr;
      n1->nbr_len = temp->nbr_len;
      free(temp->frac);
      free(temp);
      m_denom2(n1, n2);
    }
}

t_nbr	*check_zero(t_nbr *n, int frac)
{
  int	i, len, n_len;
  char	**nbr, *temp;

  nbr = frac ? &(n->frac) : &(n->nbr);
  len = frac ? n->frac_len : n->nbr_len;
  for (i = 0; i < len && (*nbr)[i] == n->base->base[0]; i++) ;
  if ((n_len = (len - i < 1) ? 1 : (len - i)) != len)
    {
      if (!(temp = malloc(n_len)))
	my_puterror(E_THE_WORLD_IS_OVER);
      if (frac)
	{
	  my_strncpy(temp, &(n->frac)[len - n_len], n->frac_len = n_len);
	  free(n->frac);
	  n->frac = temp;
	}
      else
	{
	  my_strncpy(temp, &(n->nbr)[len - n_len], n->nbr_len = n_len);
	  if (n->makefree)
	    free(n->nbr);
	  n->nbr = temp;
	}
    }
  return n;
}
