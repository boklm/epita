/*
** func3.h for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Thu Dec 19 19:02:58 2002 bruno legros
** Last update Fri Dec 20 11:20:14 2002 bruno legros
*/

#ifndef FUNC3_H
# define FUNC3_H

# include "func.h"
# include "../utils.h"
# include "../execute/vm_execute.h"

int	not_implemented(t_func_arg *arg);
int	ll(t_func_arg *arg);
int	bz(t_func_arg *arg);
int	bnz(t_func_arg *arg);
int	ld(t_func_arg *arg);

#endif /* !FUNC3_H */
