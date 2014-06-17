/*
** init_arg.h for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:49:53 2002 eric augustin
** Last update Sun Dec 22 15:49:55 2002 eric augustin
*/
#ifndef INIT_ARG_H
# define INIT_ARG_H

# include "../functions/func.h"

void		init_arg(char inst[3], t_func_arg *arg);

typedef void	(*t_init)(char inst[3], t_func_arg *);


/*
** ----- in init1.c -----
*/

/*
** for live, lp
*/
void	init1(char inst[3], t_func_arg *arg);

/*
** for mov, swap, not, and, or, xor, add, sub, rsb, neg, fl
*/
void	init2(char inst[3], t_func_arg *arg);

/*
** for rol, asr, inc, dec, lsl, lsr, stat
*/
void	init3(char inst[3], t_func_arg *arg);

/*
** for bnz, bz
*/
void	init4(char inst[3], t_func_arg *arg);

/*
** for ld, st
*/
void	init5(char inst[3], t_func_arg *arg);

/*
** ----- in init2.c -----
*/

/*
** for die, fork, nop
*/
void	init0(char inst[3], t_func_arg *arg);

/*
** for lc
*/
void	init6(char inst[3], t_func_arg *arg);

/*
** for ll
*/
void	init7(char inst[3], t_func_arg *arg);

/*
** for push, pop, jmp, write
*/
void	init8(char inst[3], t_func_arg *arg);


#endif /* !INIT_ARG_H */
