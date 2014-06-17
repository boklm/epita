/*
** init.h for corewar in /u/a1/legros_b/c/rendu/proj/corewar
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 15:06:26 2002 bruno legros
** Last update Wed Dec 18 11:18:52 2002 bruno legros
*/

#ifndef INIT_H
# define INIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "vm.h"
# include "utils.h"
# include "add_proc_in_vm.h"
# include "error/my_error.h"
# include "common/my_atoi.h"

void	init_vm(t_vm *vm);
int	init(t_vm *vm, char **players);

#endif /* !INIT.H */
