/*
** func2.h for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 18 15:31:15 2002 bruno legros
** Last update Thu Dec 19 19:35:53 2002 bruno legros
*/

#ifndef FUNC2_H
# define FUNC2_H

# include "func.h"
# include "../gest_proc/gest_proc.h"
# include "../write/write.h"
# include "../execute/vm_execute.h"
# include "../utils.h"
# include "../add_proc_in_vm.h"
# include "../common/my_strlen.h"

int	or(t_func_arg *arg);
int	xor(t_func_arg *arg);
int	st(t_func_arg *arg);
int	jmp(t_func_arg *arg);
int	my_fork(t_func_arg *arg);

#endif /* !FUNC2_H */
