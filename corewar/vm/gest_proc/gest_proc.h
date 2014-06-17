/*
** gest_proc.h for corewar in /u/a1/august_e/corewar/vm/gest_proc
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 16:08:43 2002 eric augustin
** Last update Sun Dec 22 16:08:45 2002 eric augustin
*/

#ifndef GEST_PROC_H
# define GEST_PROC_H

# include <stdlib.h>
# include "../vm.h"

void		free_proc(t_proc *proc);
void		suppr_proc(t_vm *vm, t_proc *proc);
t_proc		*find_first_proc(t_proc *proc, unsigned int n);
int		suppr_first_proc(t_proc *proc, unsigned int n);

#endif /* !GEST_PROC_H */
