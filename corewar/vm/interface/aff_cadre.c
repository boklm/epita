/*
** aff_cadre.c for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sat Dec 21 17:20:54 2002 olivier lecornet
** Last update Sun Dec 22 18:24:33 2002 olivier lecornet
*/

#include "aff.h"

void	disp_text(t_vm *vm)
{
  int	len;

  len = ((vm->env->col - 17) / 3) - 10;
  if (len < 0)
    len = 0;
  my_move(5, len);
  the_write(gl_termfd, "Memory (scale : ", strlen("Memory (scale : "));
}

static void	disp_up(t_vm *vm)
{
  my_move(1, 0);
  the_write(gl_termfd, "           ___   ___  ____   ____",
	    strlen("           ___   ___  ____   ____"));
  my_move(2, 0);
  the_write(gl_termfd, "          / __| / _ ||  _ \\ | __/",
	    strlen("          / __| / _ ||  _ \\ | __/"));
  my_move(3, 0);
  the_write(gl_termfd, "   ______| |__ | // ||    / | >_",
	    strlen("   ______| |__ | // ||    / | >_"));
  my_move(4, 0);
  the_write(gl_termfd, "  / ______\\___||___/ |_|\\_\\ |___\\",
	    strlen("  / ______\\___||___/ |_|\\_\\ |___\\"));
  my_move(5, 0);
  the_write(gl_termfd, " / /", strlen(" / /"));
  my_move(3, vm->env->col - 4);
  the_write(gl_termfd, "__   ", strlen("__   "));
  my_move(4, vm->env->col - 4);
  the_write(gl_termfd, "_ \\  ", strlen("_ \\  "));
  my_move(5, vm->env->col - 4);
  the_write(gl_termfd, " \\ \\ ", strlen(" \\ \\ "));
}

static void	disp_down(t_vm *vm)
{
  my_move(vm->env->line - 4, vm->env->col - 29);
  the_write(gl_termfd, "__    _   ___   __________/ / ",
	    strlen("__    _   ___   __________/ / "));
  my_move(vm->env->line - 3, vm->env->col - 29);
  the_write(gl_termfd, "| |  | | / _ \\ |  _ \\______/  ",
	    strlen("| |  | | / _ \\ |  _ \\______/  "));
  my_move(vm->env->line - 2, vm->env->col - 29);
  the_write(gl_termfd, "| |/\\| ||  _  ||    /", strlen("| |/\\| ||  _  ||    /"));
  my_move(vm->env->line - 1, vm->env->col - 29);
  the_write(gl_termfd, " \\_/\\_/ |_| |_||_|\\_\\",
	    strlen(" \\_/\\_/ |_| |_||_|\\_\\"));
  my_move(vm->env->line - 4, 0);
  the_write(gl_termfd, " \\ \\_", strlen(" \\ \\_"));
  my_move(vm->env->line - 3, 0);
  the_write(gl_termfd, "  \\__", strlen("  \\__"));
}


void	disp_cadre2(t_vm *vm, int i, int j)
{
  the_write(gl_termfd, "| |", 3);
  if (i == 6)
    {
      for (j = 0; (j < vm->env->col - 23 - 4); j++)
	the_write(gl_termfd, "-", 1);
      the_write(gl_termfd, "|", 1);
      for (j += 1; (j < vm->env->col - 6); j++)
	the_write(gl_termfd, " ", 1);
    }
  my_move(i, vm->env->col - 27);
  the_write(gl_termfd, "|", 1);
  for (j = vm->env->col - 29; j < vm->env->col - 6; j++)
    the_write(gl_termfd, " ", 1);
  the_write(gl_termfd, "| |\n", 4);
}

void	disp_cadre(t_vm *vm)
{
  int	i, j;

  the_write(gl_termfd, "\n\n", 2);
  for (i = 0; i < vm->env->col; i++)
    the_write(gl_termfd, "_", 1);
  for (i = 0; i < vm->env->col; i++)
    the_write(gl_termfd, "_", 1);
  for (i = 5; i < vm->env->line - 4; i++)
    disp_cadre2(vm, i, j);
  for (i = 0; i < vm->env->col; i++)
    the_write(gl_termfd, "_", 1);
  for (i = 0; i < vm->env->col; i++)
    the_write(gl_termfd, "_", 1);
  disp_up(vm);
  disp_down(vm);
  disp_text(vm);
}
