/*
** func4.h for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Fri Dec 20 11:21:40 2002 bruno legros
** Last update Fri Dec 20 16:10:02 2002 bruno legros
*/

#ifndef FUNC4_H
# define FUNC4_H

# include <stdlib.h>
# include <unistd.h>
# include "func.h"
# include "../error/my_error.h"
# include "../utils.h"
# include "../execute/vm_execute.h"

int	lp(t_func_arg *arg);
int	fl(t_func_arg *arg);
int	my_write2(t_func_arg *arg);
int	my_stat(t_func_arg *arg);
int	lc(t_func_arg *arg);

#endif /* !FUNC4_H */
