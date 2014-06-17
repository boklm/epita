/*
** func6.h for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Fri Dec 20 19:35:19 2002 bruno legros
** Last update Fri Dec 20 20:16:00 2002 bruno legros
*/

#ifndef FUNC6_H
# define FUNC6_H

# include "func.h"
# include "../error/my_error.h"
# include "../utils.h"
# include "../execute/vm_execute.h"

int	rsb(t_func_arg *arg);
int	inc(t_func_arg *arg);
int	dec(t_func_arg *arg);
int	lsl(t_func_arg *arg);
int	lsr(t_func_arg *arg);

#endif /* !FUNC6_H */
