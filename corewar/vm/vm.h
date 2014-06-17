#ifndef VM_H
# define VM_H

# include "../data.h"

# define DUMP		1
# define STEP		2
# define TRACE		4
# define BONBON		8

# define NOTHING	0
# define READING	1
# define WAITING	2
# define EXECUTE	3
# define WAIT_AFTER	4

# define NB_CMDS	33

typedef struct  s_aff_player
{
  char          *color;
  char          *id;
}               t_aff_player;

typedef struct  s_env
{
  int           line;
  int           col;
  int           nb_player;
  int           scale;
  char          *mem;
  int		nb_proc_t[15];
}               t_env;

typedef struct		s_qrt
{
  char			qrt;
  int			num;
  struct s_qrt		*next;
}			t_qrt;

typedef struct		s_write
{
  unsigned int		addr;
  t_qrt			*qrt;
  struct s_write	*next;
}			t_write;

typedef struct		s_rw
{
  char			inst[3];
  int			cur_pos;
  int			size;
  int			delay;
}			t_rw;

typedef struct		s_wbuf
{
  char			buf[2];
  int			place;
}			t_wbuf;

typedef struct		s_proc
{
  t_rw			*rw;
  t_wbuf		*wbuf;
  unsigned char		reg[16][2];
  char			stack[16][2];
  unsigned int		stack_p;
  unsigned char		pc[2];
  char			p;
  char			z;
  unsigned int		live;
  unsigned int		num;
  int			begining_is_pair;
  int			cur_work;
  char			*name;
  char			*comment;
  struct s_proc		*next;
}			t_proc;

typedef struct		s_vm
{
  int			flags;
  unsigned int		proc_per_player[15];
  unsigned int		nb_cycles;
  unsigned int		last_live[15];
  unsigned int		tmp_lives[15];
  unsigned int		lives_per_cycle;
  unsigned int		c_to_d;
  unsigned int		epoch;
  unsigned int		delta;
  char			*mem;
  unsigned int		size;
  unsigned int		max_proc;
  unsigned int		idx_mod;
  int			dump;
  unsigned int		nb_players;
  t_write		*vmwrite;
  t_proc		*proc;
  t_proc		*proc_tmp;
  t_env			*env;
}			t_vm;

#endif /* !VM_H */
