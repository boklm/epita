/*
** vm_func2.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:54:49 2002 eric augustin
** Last update Sun Dec 22 15:54:51 2002 eric augustin
*/
#include <stdlib.h>
#include <unistd.h>
#include "../vm.h"
#include "vm_execute.h"
#include "../common/my_atoi.h"
#include "../common/my_itoa.h"
#include "../common/my_hexdump.h"
#include "../common/my_strlen.h"
#include "../common/is_num.h"
#include "../interface/aff.h"

int	is_game_set(t_vm *vm)
{
  if (vm->proc == NULL)
    return 0;
  return 1;
}

int	step_by_step(t_vm *vm)
{
  char	buf[256];
  int	ok;
  int	i;

  my_hexdump(vm->mem, vm->size / 2);
  for (ok = 0; !ok; ok = ok)
  {
    i = read(STDIN_FILENO, buf, 256);
    buf[i - 1] = 0;
    if (is_num(buf))
      ok = 1;
  }
  i = my_atoi(buf);
  return (i);
}

void	check_if_new_epoch(t_vm *vm)
{
  int	new_lives;
  int	i;

  while (vm->lives_per_cycle >= vm->epoch)
  {
    vm->lives_per_cycle -= vm->epoch;
    vm->c_to_d -= vm->delta;
  }
  for (new_lives = 0, i = 0; i < 15; i++)
    if (vm->last_live[i])
      new_lives = 1;
  if (new_lives)
    for (i = 0; i < 15; i++)
    {
      vm->tmp_lives[i] = vm->last_live[i];
      vm->last_live[i] = 0;
    }
}

static void	write_player(t_vm *vm, char **players)
{
  unsigned int	i;
  char		*str;

  for (i = 0; i < 15; i++)
    if (vm->tmp_lives[i])
      break ;
  write(STDOUT_FILENO, " ", 1);
  str = my_itoa(i);
  write(STDOUT_FILENO, str, my_strlen(str));
  free(str);
  write(STDOUT_FILENO, "(", 1);
  write(STDOUT_FILENO, players[i - 1], my_strlen(players[i - 1]));
  write(STDOUT_FILENO, ")", 1);
  vm->tmp_lives[i] = 0;
}

static void	no_win(t_vm *vm, char **players, int w_exist)
{
#ifdef BONUS
  if (vm->flags & BONBON)
    aff_result(vm, players, w_exist, 0);
  else
#endif
  {
    w_exist = 0;
    vm = vm;
    players = players;
    write(STDOUT_FILENO, "Aucun gagnant.\n", 15);
  }
}

static void     multi_win(t_vm *vm, char **players, int w_exist)
{
#ifdef BONUS
  if (vm->flags & BONBON)
    aff_result(vm, players, w_exist, 1);
  else
#endif
    {
      w_exist = 0;
      write(STDOUT_FILENO, "Le joueur", 9);
      write_player(vm, players);
      write(STDOUT_FILENO, " a gagne.\n", 10);
    }
}

static void	one_win(t_vm*vm, char **players, int w_exist)
{
  int	i;

#ifdef BONUS
  if (vm->flags & BONBON)
    aff_result(vm, players, w_exist, 2);
  else
#endif
    {
      write(STDOUT_FILENO, "Egalite entre les joueurs", 25);
      for (i = 0; i < w_exist; i++)
	write_player(vm, players);
      write(STDOUT_FILENO, "\n", 1);
    }
}

void	the_winner_is(t_vm *vm, char **players)
{
  int	w_exist;
  int	i;

  for (w_exist = 0, i = 0; i < 15; i++)
    if (vm->tmp_lives[i])
      w_exist++;
  if (!w_exist)
    no_win(vm, players, w_exist);
  else if (w_exist == 1)
    multi_win(vm, players, w_exist);
  else
   one_win(vm, players, w_exist);
}
