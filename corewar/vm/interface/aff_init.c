/*
** aff_init.c for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sat Dec 21 17:21:37 2002 olivier lecornet
** Last update Sun Dec 22 18:34:29 2002 olivier lecornet
*/

#include "aff.h"

int	open_terminal(void)
{
  char	term_device_name[L_ctermid];
  int	fd;

  if (ctermid(term_device_name) == NULL)
    the_write(STDERR_FILENO, "ctermid", strlen("ctermid"));
  fd = open(term_device_name, O_RDWR);
  if (fd == -1)
    the_write(STDERR_FILENO, term_device_name, strlen(term_device_name));
  return (fd);
}

void	init_aff(t_vm *vm)
{
  t_env	*env;
  int	error, i;
  char	*cap;

  init_signaux();
  env = my_malloc(sizeof (t_env));
  setupterm(NULL, 0, &error);
  env->line = tigetnum("lines");
  env->col = tigetnum("cols");
  env->mem = my_malloc(vm->size * sizeof (char));
  for (i = 0; i < vm->size; i++)
    env->mem[i] = 0;
  for (i = 0; i < 15; i++)
    env->nb_proc_t[i] = 0;
  env->nb_player = vm->nb_players;
  vm->env = env;
  gl_termfd = open_terminal();
  gl_redraw = 1;
}

void	test_redraw(t_vm *vm)
{
  if (gl_redraw)
    {
      cl_screen();
      actual_cadre(vm);
      disp_cadre(vm);
      aff_all_table(vm);
      gl_redraw = 0;
    }
  aff_info_player(vm);
}
