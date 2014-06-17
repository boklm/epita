/*
** xmalloc.h for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Wed Dec 11 11:56:15 2002 olivier lecornet
** Last update Thu Dec 12 13:21:35 2002 olivier lecornet
*/

#ifndef MY_SYSTEM_H
# define MY_SYSTEM_H

#include "../asm.h"

void	*xmalloc(int n);
int	my_write(int fd, char *s, int size);
int	my_read(int fd, char *s, int size);

#endif /* MY_SYSTEM_H */
