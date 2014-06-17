/*
** aff_info_player.c for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sat Dec 21 17:21:27 2002 olivier lecornet
** Last update Sun Dec 22 18:33:40 2002 olivier lecornet
*/

#include "aff.h"

int	gl_termfd;

t_aff_player	tab[MAX_NB_PLAYER] =
  {{MY_GREEN_CL, "  1 ("},
   {MY_YELLOW, "  2 ("},
   {MY_RED_CL, "  3 ("},
   {MY_PURPLE_CL, "  4 ("},
   {MY_BLUE_CL, "  5 ("},
   {MY_GRIS_DARK, "  6 ("},
   {MY_CYAN_CL, "  7 ("},
   {MY_WHITE, "  8 ("},
   {MY_GRIS, "  9 ("},
   {MY_CYAN, " 10 ("},
   {MY_PURPLE, " 11 ("},
   {MY_BLUE, " 12 ("},
   {MY_RED, " 13 ("},
   {MY_BROWN, " 14 ("},
   {MY_GREEN, " 15 ("}
  };

char    *my_itoa_base(int nbr, char *base, int base_size)
{
  int   i, j;
  char  tmp[30], *res;

  if (nbr == 0)
    {
      res = my_malloc(sizeof (char) * 2);
      res[0] = '0';
      res[1] = 0;
      return (res);
    }
  for (i = 0; nbr > 0; i++)
    {
      tmp[i] = base[nbr % base_size];
      nbr /= base_size;
    }
  res = my_malloc(sizeof (char) * i);
  res[i] = '\0';
  for (j = 0; j < i; j++)
    res[j] = tmp[i - 1 - j];
  return (res);
}

void	init_info_player(int nb_proc[MAX_NB_PLAYER], t_proc *tete)
{
  int		i;
  t_proc	*p;

  for (i = 0; i < MAX_NB_PLAYER; i++)
    nb_proc[i] = 0;
  for (p = tete; p; p = p->next)
    nb_proc[p->num - 1]++;
}

void	printable_player(t_vm *vm, int i)
{
  char	*res;

  the_write(gl_termfd, tab[i].color, strlen(tab[i].color));
  the_write(gl_termfd, "Player", strlen("Player"));
  the_write(gl_termfd, tab[i].id, strlen(tab[i].id));
  res = my_itoa_base(vm->proc_per_player[i], "0123456789", 10);
  the_write(gl_termfd, res, strlen(res));
  free(res);
  the_write(gl_termfd, ")\n", strlen(")\n"));
  the_write(gl_termfd, MY_NORM, strlen(MY_NORM));
}

int	aff_info_player(t_vm *vm)
{
  int		i, modif;

  modif = 0;
  for (i = 0; i < vm->env->nb_player && (i < vm->env->line - 12); i++)
    {
      my_move(7 + i, vm->env->col - 22);
      if (vm->proc_per_player[i])
	printable_player(vm, i);
       else
	 the_write(gl_termfd, "                ", strlen("                "));
      if ((vm->env->nb_proc_t[i] != vm->proc_per_player[i]) &&
	   (vm->proc_per_player[i] == 0))
	{
	  modif = 1;
	  delete_player_table(i, vm->env->mem, vm->size);
	}
      vm->env->nb_proc_t[i] = vm->proc_per_player[i];
    }
  if (i < vm->env->nb_player)
    {
      my_move(7 + i, vm->env->col - 17);
      the_write(gl_termfd, "...", strlen("..."));
    }
  if (modif)
    redraw_table(vm);
  return (0);
}
