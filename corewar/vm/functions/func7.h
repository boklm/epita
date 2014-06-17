/*
** func7.h for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Fri Dec 20 19:35:19 2002 bruno legros
** Last update Fri Dec 20 20:16:00 2002 bruno legros
*/

#ifndef FUNC7_H
# define FUNC7_H

# include "func.h"
# include "../error/my_error.h"
# include "../utils.h"
# include "../execute/vm_execute.h"

int	rol(t_func_arg *arg);
int	asr(t_func_arg *arg);

#endif /* !FUNC7_H */
