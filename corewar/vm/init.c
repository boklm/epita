/*
** init.c for corewar in /u/a1/legros_b/c/rendu/proj/corewar
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Wed Dec  4 14:15:26 2002 bruno legros
** Last update Sun Dec 22 19:09:49 2002 eric augustin
*/

#include "stdlib.h"
#include "init.h"
#include "interface/aff_table.h"

void	name_open_read(int *fd, char *file)
{
  int		r;
  unsigned char	buf[4];

  if ((*fd = open(file, O_RDONLY)) < 0)
    my_error("*** Error opening ", file, NULL, 1);
  if ((r = read(*fd, buf, 4)) < 0)
    my_error("*** Error reading ", file, NULL, 1);
  if (r != 4 || !comp_magic(buf, COREWAR_EXEC_MAGIC))
    my_error("*** Error file not in good format (magic): ", file, NULL, 2);
}

static int	get_name_comment_fd(char *file,
				    char **name,
				    char **comment,
				    unsigned int *code_size)
{
  int		r;
  int		fd;
  unsigned char	buf[4];

  name_open_read(&fd, file);
  if ((r = read(fd, buf, 4)) < 0)
    my_error("*** Error reading ", file, NULL, 1);
  *code_size = get_code_size(buf);
  if (r != 4)
    my_error("*** Error file not in good format (code size): ", file, NULL, 2);
  *name = my_malloc(PROG_NAME_LENGTH + 1);
  if ((r = read(fd, *name, PROG_NAME_LENGTH)) < 0)
    my_error("*** Error reading ", file, NULL, 1);
  if (r != PROG_NAME_LENGTH)
    my_error("*** Error file not in good format (name): ", file, NULL, 2);
  (*name)[r] = 0;
  *comment = my_malloc(PROG_COMMENT_LENGTH + 1);
  if ((r = read(fd, *comment, PROG_COMMENT_LENGTH)) < 0)
    my_error("*** Error reading ", file, NULL, 1);
  if (r != PROG_COMMENT_LENGTH)
    my_error("*** Error file not in good format (comment): ", file, NULL, 2);
  (*comment)[r] = 0;
  return fd;
}

static t_proc	*create_proc(t_vm *vm, int num, unsigned int pc)
{
  t_proc	*proc;
  int		i;

  proc = my_malloc(sizeof (t_proc));
  proc->wbuf = my_malloc(sizeof (t_wbuf));
  proc->rw = my_malloc(sizeof (t_rw));
  num2reg(pc, proc->pc);
  proc->num = num;
  num2reg(num, proc->reg[0]);
  for (i = 1; i < 16; i++)
    proc->reg[i][1] = proc->reg[i][0] = 0;
  proc->p = proc->live = 0;
  proc->z = 1;
  for (i = 0; i < 16; i++)
    proc->stack[i][0] = proc->stack[i][1] = 0;
  proc->stack_p = 0;
  for (i = 0; i < 3; i++)
    proc->wbuf->buf[i] = proc->rw->inst[i] = 0;
  proc->rw->cur_pos = 0;
  proc->wbuf->place = -1;
  proc->rw->size = 0;
  proc->rw->delay = 0;
  proc->begining_is_pair = pc % 2;
  proc->cur_work = READING;
  add_proc_in_vm(vm, proc);
  return proc;
}

/*
** copy player [num] code to place [place] in the mem
** and create a processor by player
** [place] is in quartets
** [file] is the filename of the file containing the code
*/
static t_proc		*create_player(t_vm *vm,
				      char *file,
				      int num,
				      unsigned int place)
{
  char			*name, *comment, c;
  int			r, fd;
  unsigned int		code_size, i;
  t_proc		*proc;

  if ((fd = get_name_comment_fd(file, &name, &comment, &code_size)) < 0)
    exit(1);
  proc = create_proc(vm, num, place);
  proc->name = name;
  proc->comment = comment;
  if (code_size > vm->size / vm->nb_players)
    my_error("*** Error, code is too long for player ", name, NULL, 2);
  for (i = place / 2; (r = read(fd, &c, 1)) > 0 && i < vm->size / 2 &&
	 (i - (place / 2)) < code_size; i++)
    {
      if (place % 2)
      {
	vm->mem[i] |= (c & 0xf0) >> 4;
	vm->mem[i + 1] |= (c & 0x0f) << 4;
      }
      else
	vm->mem[i] = c;
#ifdef BONUS
      if (vm->flags & BONBON)
	{
	  init_player_table(vm, num, i * 2, vm->env->mem);
	  init_player_table(vm, num, i * 2 + 1, vm->env->mem);
	}
#endif
    }
  if (close(fd) < 0)
    my_error("Error closing file ", file, NULL, 1);
  return proc;
}

static void	check_const(t_vm *vm)
{
  if (vm->size > 65535)
    my_error("*** Error memory size is too big, max size is 65535 quartets",
	     "", NULL, 2);
  if (vm->epoch > 65535)
    my_error("*** Error EPOCH is too big, max size is 65535", "", NULL, 2);
  if (vm->delta > 65535)
    my_error("*** Error CYCLES_DELTA is too big, max size is 65535", "",
	     NULL, 2);
  if (vm->c_to_d > 65535)
    my_error("*** Error CYCLES_TO_DEATH is too big, max size is 65535", "",
	     NULL, 2);
  if (vm->idx_mod > 65535)
    my_error("*** Error IDX_MOD is too big, max size is 65535", "", NULL, 2);
}

/*
** [players] is the list of filenames which contains the code (*.cor)
** mem size is always pair
*/
int			init(t_vm *vm, char **players)
{
  unsigned int		j;
  unsigned int		i;
  int			k;
  t_proc		*proc;

  check_const(vm);
  vm->mem = my_malloc(vm->size / 2);
  for (i = 0; i < (vm->size / 2); i++)
    vm->mem[i] = 0;
  for (i = j = 0; j < vm->nb_players; i += vm->size / vm->nb_players, j++)
    {
      proc = create_player(vm, players[j], j + 1, i);
      players[j] = my_malloc(my_strlen(proc->name) + 1);
      for (k = 0; k < my_strlen(proc->name); k++)
	players[j][k] = proc->name[k];
    }
  return 0;
}

void		init_vm(t_vm *vm)
{
  int		i;
  unsigned int	j;

  vm->vmwrite = NULL;
  vm->flags = 0;
  for (j = 0; j < 15; vm->proc_per_player[j] = 0, j++) ;
  vm->nb_cycles = 0;
  for (i = 0; i < 15; vm->last_live[i] = 0, i++) ;
  for (i = 0; i < 15; vm->tmp_lives[i] = 0, i++) ;
  vm->lives_per_cycle = 0;
  vm->c_to_d = CYCLES_TO_DEATH;
  vm->epoch = EPOCH;
  vm->delta = CYCLES_DELTA;
  vm->mem = NULL;
  vm->size = MEM_SIZE;
  vm->max_proc = MAX_PROCESSORS;
  vm->idx_mod = IDX_MOD;
  vm->dump = -1;
  vm->nb_players = 0;
  vm->proc = NULL;
  vm->proc_tmp = NULL;
}
