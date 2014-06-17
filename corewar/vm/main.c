/*
** main.c for corewar in /u/a1/legros_b/c/rendu/proj/corewar
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 16:10:31 2002 bruno legros
** Last update Sun Dec 22 09:07:40 2002 olivier lecornet
*/

#include "main.h"
#include "interface/aff.h"

int		main(int argc, char **argv)
{
  t_vm		vm;
  int		pos;
  char		**players;
  unsigned int	j;

  init_vm(&vm);
  pos = take_arg(argc, argv, &vm);
  players = argv + pos;
  vm.nb_players = argc - pos;
  if (vm.nb_players > 15)
    my_error(argv[0], ":Error: Too many champions.\n", NULL, 1);
  for (j = 0; j < vm.nb_players; vm.proc_per_player[j] = 1, j++) ;
#ifdef BONUS
  if (vm.flags & BONBON)
    init_aff(&vm);
#endif
  init(&vm, players);
  vm_execute(&vm, players);
  return 0;
}
