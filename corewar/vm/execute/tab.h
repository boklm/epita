/*
** tab.h for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:50:11 2002 eric augustin
** Last update Sun Dec 22 15:50:12 2002 eric augustin
*/
#ifndef TAB_H
# define TAB_H

# include "../vm.h"
# include "../functions/func.h"
# include "../functions/func1.h"
# include "../functions/func2.h"
# include "../functions/func3.h"
# include "../functions/func4.h"
# include "../functions/func5.h"
# include "../functions/func6.h"
# include "../functions/func7.h"
# include "init_arg.h"
# include "trace.h"

typedef struct	s_cmd
{
  char		*name;
  unsigned char	code;
  int		size;
  int		sig1;
  int		sig2;
  int		size_inst;
  int		delay;
  t_func	func;
  t_init	set_arg;
  t_trfunc	tr;
}		t_cmd;


static t_cmd   cmds[NB_CMDS] =
  {
    {"die", 0x00, 2, 1, 0, 2, DELAY_DIE, live_or_die, init0, tr0},
    {"live", 0x0f, 2, 1, 0, 1, DELAY_LIVE, live_or_die, init1, tr1},
    {"mov", 0x10, 4, 1, 0, 2, DELAY_ARITH, mov, init2, tr2},
    {"swp", 0x11, 4, 1, 0, 2, DELAY_ARITH, swp, init2, tr2},
    {"not", 0x12, 4, 1, 0, 2, DELAY_ARITH, not, init2, tr2},
    {"and", 0x13, 4, 1, 0, 2, DELAY_ARITH, and, init2, tr2},
    {"or", 0x14, 4, 1, 0, 2, DELAY_ARITH, or, init2, tr2},
    {"xor", 0x15, 4, 1, 0, 2, DELAY_ARITH, xor, init2, tr2},
    {"rol", 0x16, 4, 1, 0, 2, DELAY_ARITH, rol, init3, tr3},
    {"asr", 0x17, 4, 1, 0, 2, DELAY_ARITH, asr, init3, tr3},
    {"add", 0x18, 4, 1, 0, 2, DELAY_ARITH, add, init2, tr2},
    {"sub", 0x19, 4, 1, 0, 2, DELAY_ARITH, sub, init2, tr2},
    {"rsb", 0x1a, 4, 1, 0, 2, DELAY_ARITH, rsb, init2, tr2},
    {"neg", 0x1b, 4, 1, 0, 2, DELAY_ARITH, neg, init2, tr2},
    {"inc", 0x1c, 4, 1, 0, 2, DELAY_ARITH, inc, init3, tr3},
    {"dec", 0x1d, 4, 1, 0, 2, DELAY_ARITH, dec, init3, tr3},
    {"lsl", 0x1e, 4, 1, 0, 2, DELAY_ARITH, lsl, init3, tr3},
    {"lsr", 0x1f, 4, 1, 0, 2, DELAY_ARITH, lsr, init3, tr3},
    {"lp", 0x2f, 2, 1, 0, 1, DELAY_LP, lp, init1, tr1},
    {"bnz", 0x3f, 2, 0, 0, 1, DELAY_CBRANCH, bnz, init4, tr4},
    {"bz", 0xbf, 2, 0, 0, 1, DELAY_CBRANCH, bz, init4, tr4},
    {"ld", 0x4f, 3, 1, 0, 1, DELAY_LD, ld, init5, tr2},
    {"st", 0x5f, 3, 1, 0, 1, DELAY_ST, st, init5, tr2},
    {"lc", 0x6f, 4, 0, 0, 1, DELAY_LC, lc, init6, tr3},
    {"ll", 0xef, 6, 0, 0, 1, DELAY_LL, ll, init7, tr3},
    {"fork", 0x70, 2, 1, 1, 2, DELAY_FORK, my_fork, init0, tr0},
    {"push", 0x71, 3, 1, 1, 2, DELAY_STACK, push, init8, tr4},
    {"pop", 0x72, 3, 1, 1, 2, DELAY_STACK, pop, init8, tr4},
    {"jmp", 0x73, 3, 1, 1, 2, DELAY_JMP, jmp, init8, tr4},
    {"fl", 0x74, 4, 1, 1, 2, DELAY_FL, fl, init2, tr2},
    {"write", 0x75, 3, 1, 1, 2, DELAY_WRITE, my_write2, init8, tr4},
    {"stat", 0x76, 4, 1, 1, 2, DELAY_STAT, my_stat, init3, tr3},
    {"nop", 0x77, 2, 1, 1, 2, DELAY_NOP, not_implemented, init0, tr0}
  };

#endif /* !TAB_H */
