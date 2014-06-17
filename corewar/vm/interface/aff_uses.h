#ifndef AFF_USES_H
# define AFF_USES_H

# include "aff.h"

int	the_write(int fd, char *s, int size);
void	cl_screen(void);
char	*pos_curser(int x, int y);
void	actual_cadre(t_vm *vm);

#endif /* AFF_USES_H */
