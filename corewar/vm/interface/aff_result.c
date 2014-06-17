/*
** aff_result.c for  in /u/a1/lecorn_o/c/corewar/vm/interface
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sun Dec 22 00:55:51 2002 olivier lecornet
** Last update Sun Dec 22 18:27:44 2002 olivier lecornet
*/

#include "aff.h"

static void	my_write_player(t_vm *vm, char **players)
{
  unsigned int	i;
  char		*str;

  for (i = 0; i < 15; i++)
    if (vm->tmp_lives[i])
      break ;
  str = my_itoa_base(i, "0123456789", 10);
  if (i < 10)
    write(gl_termfd, " ", 1);
  write(gl_termfd, str, strlen(str));
  free(str);
  write(gl_termfd, "(", 1);
  write(gl_termfd, players[i - 1], strlen(players[i - 1]));
  write(gl_termfd, ")", 1);
  vm->tmp_lives[i] = 0;
}

void	no_winner(t_vm *vm)
{
  int	line, col;

  line = (vm->env->line / 2) - 1;
  col = (vm->env->col / 2) - 7;
  if (line < 0)
    line = 0;
  if (col < 0)
    col = 0;
  my_move(line, col);
  the_write(gl_termfd, "+-------------+\n", strlen("+-------------+\n"));
  my_move(line + 1, col);
  the_write(gl_termfd, "|  NO WINNER  |\n", strlen("|  NO WINNER  |\n"));
  my_move(line + 2, col);
  the_write(gl_termfd, "+-------------+", strlen("+-------------+"));
  sleep(5);
  cl_screen();
}

void	winner_is(t_vm *vm, char **player)
{
  int   line, col, len, i;

  line = (vm->env->line / 2) - 1;
  col = (vm->env->col / 2) - 6;
  if (line < 0)
    line = 0;
  if (col < 0)
    col = 0;
  my_move(line, col);
  the_write(gl_termfd, "THE WINNER IS :", strlen("THE WINNER IS :"));
  col = (vm->env->col / 2) - (strlen(player[0]) / 2);
  my_move(line + 1, col);
  my_write_player(vm, player);
  sleep(5);
  cl_screen();
}

void	equality(t_vm *vm, char **player, int nb)
{
  int   line, col, len, i;

  line = (vm->env->line / 2) - (nb / 2) - 1;
  col = (vm->env->col / 2) - 8;
  if (line < 0)
    line = 0;
  if (col < 0)
    col = 0;
  my_move(line, col);
  the_write(gl_termfd, "THE WINNERS ARE :", strlen("THE WINNERS ARE :"));
  for (i = 0; i < nb; i++)
    {
      col = (vm->env->col / 2) - (strlen(player[i]) / 2);
      my_move(line + i + 2, col);
      my_write_player(vm, player);
    }
  sleep(5);
  cl_screen();
}

void	aff_result(t_vm *vm, char **player, int nb, int flag)
{
  cl_screen();
  if (flag == 0)
    no_winner(vm);
  if (flag == 1)
    winner_is(vm, player);
  if (flag == 2)
    equality(vm, player, nb);
  close(gl_termfd);
}
