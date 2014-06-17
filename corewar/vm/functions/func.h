/*
** func.h for corewar in /u/a1/august_e/corewar/vm/functions
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 16:07:00 2002 eric augustin
** Last update Sun Dec 22 16:07:03 2002 eric augustin
*/

/*
** definition des parametres utilises pour les fonctions
** appelees par la machine virtuelle.
**
** si elle ne prend pas de parametre, mettre NULL
** si elle prend un entier n (ex: live), utiliser n
** die sera vue comme un live avec n == 0
*/

#ifndef FUNC_H
# define FUNC_H

# include "../vm.h"

typedef struct	s_func_arg
{
  t_vm		*vm;
  t_proc	*proc;
  unsigned int	rx;
  unsigned int	ry;
  unsigned int	n;
}		t_func_arg;

typedef int	(*t_func)(t_func_arg *);

void		inc_qrt(unsigned char r[2], unsigned int nb);
void		dec_qrt(unsigned char r[2], unsigned int nb);
void		decal_left(unsigned char r[2], char p, unsigned int n);
void		decal_right(unsigned char r[2], char p, unsigned int n);

#endif /* !FUNC_H */
