/*
** add_sub.c for bistromathique in /u/a1/legros_b/c/rendu/proj/bistromathique
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Oct 30 12:43:31 2002 bruno legros
** Last update Sat Nov  9 09:56:40 2002 bruno legros
*/

#include "bistro.h"

static t_nbr	*add_sub2(t_nbr *n1, t_nbr *n2)
{
  if (!n1->negative)
    {
      if (!n2->negative)
	return (add(n1, n2));
      else
	return (not(sub(n2, n1)));
    }
  else
    if (!n2->negative)
      return (sub(n2, n1));
    else
      return (not(add(n1, n2)));
}

t_nbr	*add_sub(t_nbr *n1, t_nbr *n2)
{
  m_denom(n1, n2);
  if (nbr_cmp(n1, n2, 0) >= 0)
    {
      if (!n1->negative)
	{
	  if (!n2->negative)
	    return (add(n1, n2));
	  else
	    return (sub(n1, n2));
	}
      else
	if (!n2->negative)
	  return (not(sub(n1, n2)));
	else
	  return (not(add(n1, n2)));
    }
  else
    return (add_sub2(n1, n2));
}

t_nbr	*add(t_nbr *n1, t_nbr *n2)
{
  int	ret, i, j, sum, k;
  t_nbr	*res;

  res = alloc_nbr(n1->base);
  i = n1->nbr_len - 1;
  k = ((n1->nbr_len - n2->nbr_len >= 0) ? n1->nbr_len : n2->nbr_len);
  if (!(res->nbr = realloc(res->nbr, k + 1)))
    my_puterror(E_THE_WORLD_IS_OVER);
  res->nbr_len = k + 1;
  for (ret = 0, j = n2->nbr_len - 1; i >= 0 || j >= 0 || ret; i--, j--, k--)
    {
      sum = bas((i < 0) ? n1->base->base[0] : n1->nbr[i], n1->base) +
	bas((j < 0) ? n1->base->base[0] : n2->nbr[j], n1->base) + ret;
      res->nbr[k] = n1->base->base[sum % n1->base->base_len];
      ret = (sum >= n1->base->base_len) ? 1 : 0;
    }
  if (k != -1)
    res->nbr[0] = res->base->base[0];
  if (!(res->frac = realloc(res->frac, n1->frac_len)))
    my_puterror(E_THE_WORLD_IS_OVER);
  my_strncpy(res->frac, n1->frac, n1->frac_len);
  res->frac_len = n1->frac_len;
  return res;
}

t_nbr	*sub(t_nbr *n1, t_nbr *n2)
{
  int	ret, i, j, sum, k;
  t_nbr	*res;

  res = alloc_nbr(n1->base);
  i = n1->nbr_len - 1;
  k = ((n1->nbr_len - n2->nbr_len >= 0) ? n1->nbr_len : n2->nbr_len) - 1;
  if (!(res->nbr = realloc(res->nbr, k + 1)))
    my_puterror(E_THE_WORLD_IS_OVER);
  res->nbr_len = k + 1;
  for (ret = 0, j = n2->nbr_len - 1; i >= 0 || j >= 0 || ret; i--, j--, k--)
    {
      sum = bas((i < 0) ? n1->base->base[0] : n1->nbr[i], n1->base) -
	bas((j < 0) ? n1->base->base[0] : n2->nbr[j], n1->base) - ret;
      ret = 0;
      if (sum < 0)
	{
	  ret = 1;
	  sum += n1->base->base_len;
	}
      res->nbr[k] = n1->base->base[sum % n1->base->base_len];
    }
  if (!(res->frac = realloc(res->frac, n1->frac_len)))
    my_puterror(E_THE_WORLD_IS_OVER);
  my_strncpy(res->frac, n1->frac, n1->frac_len);
  res->frac_len = n1->frac_len;
  return res;
}
