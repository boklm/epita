/*
** write.h for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 18 18:00:08 2002 bruno legros
** Last update Thu Dec 19 13:18:44 2002 bruno legros
*/

#ifndef WRITE_H
# define WRITE_H

# include "../vm.h"
# include "../error/my_error.h"
# include "../functions/func.h"

int	add_write(unsigned int addr, char qrt, t_func_arg *arg);
void	check_write(t_vm *vm);

#endif /* !WRITE_H */
