/*
** main.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Tue Dec  3 17:23:59 2002 olivier lecornet
** Last update Sun Dec 22 14:57:43 2002 nicolas vigier
*/

#include "asm.h"

t_cmd   cmds[NB_CMDS] =
  {
    {"die", "X0000000", NULL, NULL, 0, 0, 2},
    {"live", "X000", recup_constante, NULL, 1, 0, 2},
    {"mov", "X0010000", recup_register, recup_register, 1, 1, 4},
    {"swp", "X0010001", recup_register, recup_register, 1, 1, 4},
    {"not", "X0010010", recup_register, recup_register, 1, 1, 4},
    {"and", "X0010011", recup_register, recup_register, 1, 1, 4},
    {"or", "X0010100", recup_register, recup_register, 1, 1, 4},
    {"xor", "X0010101", recup_register, recup_register, 1, 1, 4},
    {"rol", "X0010110", recup_register, recup_constante, 1, 1, 4},
    {"asr", "X0010111", recup_register, recup_constante, 1, 1, 4},
    {"add", "X0011000", recup_register, recup_register, 1, 1, 4},
    {"sub", "X0011001", recup_register, recup_register, 1, 1, 4},
    {"rsb", "X0011010", recup_register, recup_register, 1, 1, 4},
    {"neg", "X0011011", recup_register, recup_register, 1, 1, 4},
    {"inc", "X0011100", recup_register, recup_constante, 1, 1, 4},
    {"dec", "X0011101", recup_register, recup_constante, 1, 1, 4},
    {"lsl", "X0011110", recup_register, recup_constante, 1, 1, 4},
    {"lsr", "X0011111", recup_register, recup_constante, 1, 1, 4},
    {"lp", "X010", recup_constante, NULL, 1, 0, 2},
    {"bnz", "0011", recup_register, NULL, 1, 0, 2},
    {"bz", "1011", recup_register, NULL, 1, 0, 2},
    {"ld", "X100", recup_register, recup_register_add, 1, 1, 3},
    {"st", "X101", recup_register_add, recup_register, 1, 1, 3},
    {"lc", "0110", recup_register, recup_constante, 1, 2, 4},
    {"ll", "1110", recup_register, recup_constante, 1, 4, 6},
    {"fork", "X111X000", NULL, NULL, 0, 0, 2},
    {"push", "X111X001", recup_register, NULL, 1, 0, 3},
    {"pop", "X111X010", recup_register, NULL, 1, 0, 3},
    {"jmp", "X111X011", recup_register, NULL, 1, 0, 3},
    {"fl", "X111X100", recup_register, recup_register_add, 1, 1, 4},
    {"write", "X111X101", recup_register, NULL, 1, 0, 3},
    {"stat", "X111X110", recup_register, recup_constante, 1, 1, 4},
    {"nop", "X111X111", NULL, NULL, 0, 0, 2}
  };

t_info		*alloc_t_info(char *file)
{
  t_info	*all;

  all = xmalloc(sizeof (t_info));
  all->name = NULL;
  all->comment = NULL;
  if ((all->fd_input = open(file, O_RDONLY, 0666)) == -1)
    {
      my_write(STDOUT_FILENO, file, my_strlen(file));
      my_write(STDOUT_FILENO, ERR_FILE, my_strlen(ERR_FILE));
      return (NULL);
    }
  all->inputfile = file;
  all->fd_output = 0;
  all->size_prog = 0;
  all->pos_buf = 0;
  all->size_buf = 0;
  all->line = 0;
  all->do_encode = 1;
  all->tete_words = NULL;
  all->tete_label = NULL;
  all->tete_cmd = NULL;
  return (all);
}

void		compilation_fichier(char *file, int flag)
{
  t_info	*all;

  if ((all = alloc_t_info(file)) == NULL)
    return ;
  all->flags = flag;
  if (verif_syntaxe(all) && !(flag & NC))
    output_core(all);
}

int	main(int argc, char **argv)
{
  int	flag, pos;

  pos = take_arg(argc, argv, &flag);
  if (pos >= argc)
    {
      my_write(STDERR_FILENO, ARG_NOT_ENOUGHT, my_strlen(ARG_NOT_ENOUGHT));
      exit(1);
    }
  for (pos = pos; pos < argc; pos++)
    {
      my_putstrstr("|=====> Assembling ^\n", argv[pos]);
      compilation_fichier(argv[pos], flag);
      my_putstr("______________________________\n");
    }
  return (0);
}
