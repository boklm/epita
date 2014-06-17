/*
** data.h for corewar in /u/a1/legros_b/c/rendu/proj/corewar
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec 11 14:20:32 2002 bruno legros
** Last update Mon Dec 16 13:40:13 2002 bruno legros
*/

#ifndef DATA_H
# define DATA_H

# define COREWAR_EXEC_MAGIC	0x726f6342
# define PROG_NAME_LENGTH	64
# define PROG_COMMENT_LENGTH	256
# define CYCLES_TO_DEATH	1554
# define EPOCH			700
# define CYCLES_DELTA		1
# define IDX_MOD		128
# define MAX_CODE_SIZE		65536
# define MEM_SIZE		8192
# define MAX_PROCESSORS		2048

# define DELAY_DIE		0
# define DELAY_LIVE		20
# define DELAY_ARITH		0
# define DELAY_LP		0
# define DELAY_CBRANCH		1
# define DELAY_LD		1
# define DELAY_ST		24
# define DELAY_LC		0
# define DELAY_LL		0
# define DELAY_FORK		803
# define DELAY_STACK		2
# define DELAY_JMP		20
# define DELAY_FL		5
# define DELAY_WRITE		0
# define DELAY_STAT		5
# define DELAY_NOP		0

#endif /* !DATA_H */
