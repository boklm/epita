/*
** output.c for bistromathique in /u/a1/vigier_n/bistro/my_bistro
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Fri Nov  1 13:10:52 2002 nicolas vigier
** Last update Sat Nov  9 11:58:14 2002 nicolas vigier
*/

#include "bistro.h"

void	my_putnstr(char *str, int n)
{
  while (n--)
    my_putchar(*str++);
}

void	output_nbr(t_nbr *nbr, t_bistro *bistro)
{
  my_putnstr(nbr->nbr, nbr->nbr_len);
  if (!((nbr->frac_len == 1) && (*nbr->frac == nbr->base->base[1])))
    {
      my_putchar(bistro->op_emp);
      my_putnstr(nbr->frac, nbr->frac_len);
      my_putchar(bistro->op_div);
    }
  if (nbr->negative)
    my_putchar(bistro->op_neg);
}

void	output_nbr_infix(t_nbr *nbr, t_bistro *bistro)
{
  if (nbr->negative)
    my_putchar(bistro->op_neg);
  my_putnstr(nbr->nbr, nbr->nbr_len);
  if (!((nbr->frac_len == 1) && (*nbr->frac == nbr->base->base[1])))
    {
      my_putchar(bistro->op_div);
      my_putnstr(nbr->frac, nbr->frac_len);
    }
}
