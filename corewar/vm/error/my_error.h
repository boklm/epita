/*
** my_error.h for corewar in /u/a1/legros_b/c/rendu/proj/corewar
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 14:52:50 2002 bruno legros
** Last update Sat Dec 21 18:02:47 2002 eric augustin
*/

#ifndef MY_ERROR_H
# define MY_ERROR_H

# include <unistd.h>
# include <stdlib.h>
# include "../common/my_strlen.h"

void	my_error(char *s, char *str, char *s3, int ex);
void	*my_malloc(size_t size);

#endif /* !MY_ERROR_H */
