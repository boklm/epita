/*
** utils.h for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 18 17:18:43 2002 bruno legros
** Last update Fri Dec 20 14:56:44 2002 bruno legros
*/

#ifndef UTILS_H
# define UTILS_H

void		num2reg(unsigned int num, unsigned char reg[2]);
int		neg_mod(int n, int mod);
int		reg2int(unsigned char reg[2]);
void		int2reg(unsigned char reg[2], int n);
unsigned int	get_code_size(unsigned char buf[4]);

#endif /* !UTILS_H */
