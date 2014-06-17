/*
** warn_miss_dir.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Wed Dec 11 14:43:36 2002 olivier lecornet
** Last update Thu Dec 12 12:42:31 2002 olivier lecornet
*/

#include "gest_errors.h"

void	warn_miss_dir(t_error *p, char *pref, char *med, char *suf)
{
  pref = pref;
  med = med;
  suf = suf;
  my_write(STDOUT_FILENO, p->msg, my_strlen(p->msg));
}
