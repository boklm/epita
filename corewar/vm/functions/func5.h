/*
** func5.h for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Fri Dec 20 16:29:45 2002 bruno legros
** Last update Fri Dec 20 18:48:34 2002 bruno legros
*/

#ifndef FUNC5_H
# define FUNC5_H

# include "func.h"
# include "../error/my_error.h"
# include "../utils.h"
# include "../execute/vm_execute.h"

int	push(t_func_arg *arg);
int	pop(t_func_arg *arg);
int	neg(t_func_arg *arg);
int	add(t_func_arg *arg);
int	sub(t_func_arg *arg);

#endif /* !FUNC5_H */
