/*
** func1.h for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 18 15:31:00 2002 bruno legros
** Last update Wed Dec 18 15:31:31 2002 bruno legros
*/

#ifndef FUNC1_H
# define FUNC1_H

# include "func.h"
# include "../gest_proc/gest_proc.h"

int	live_or_die(t_func_arg *arg);
int	mov(t_func_arg *arg);
int	swp(t_func_arg *arg);
int	not(t_func_arg *arg);
int	and(t_func_arg *arg);

#endif /* !FUNC1_H */
