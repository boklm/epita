/*
** trace.h for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:50:49 2002 eric augustin
** Last update Sun Dec 22 15:50:51 2002 eric augustin
*/
#ifndef TRACE_H
#define TRACE_H

# include "../functions/func.h"
# include "../vm.h"

typedef void	(*t_trfunc)(t_func_arg *arg);

void	trace_mode(t_vm *vm, t_proc *proc);

/* trace_func1.c */

/*
** for die, fork, nop
*/
void	tr0(t_func_arg *arg);

/*
** for live, lp
*/
void	tr1(t_func_arg *arg);

/*
** for mov, swap, not, and, or, xor, add, sub, rsb, neg
*/
void	tr2(t_func_arg *arg);

/*
** for rol, asr, inc, dec, lsl, lsr, stat, ll, lc
*/
void	tr3(t_func_arg *arg);

/*
** for bnz, bz, push, pop, jmp, write
*/
void	tr4(t_func_arg *arg);

/* trace_func2.c */

/*
** for ld, fl
*/
void	tr5(t_func_arg *arg);

/*
** for st
*/
void	tr6(t_func_arg *arg);

#endif /* !TRACE_H */
