/*
** add_proc_in_vm.h for corewar in /u/a1/legros_b/c/rendu/proj/corewar
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 16:07:16 2002 bruno legros
** Last update Sat Dec 21 14:41:02 2002 eric augustin
*/

#ifndef ADD_PROC_IN_VM_H
# define ADD_PROC_IN_VM_H

# include <stdlib.h>
# include "vm.h"

void	add_proc_in_vm(t_vm *vm, t_proc *proc);
void	add_proc_tmp_in_vm(t_vm *vm, t_proc *proc);

#endif /* !ADD_PROC_IN_VM_H */
