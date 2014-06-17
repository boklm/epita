/*
** vm_execute.h for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:58:46 2002 eric augustin
** Last update Sun Dec 22 15:58:48 2002 eric augustin
*/
#ifndef VM_EXECUTE_H
# define VM_EXECUTE_H

#include "../vm.h"

/* vm_execute.c */
void	vm_execute(t_vm *, char **);

/* gest_inst.c */
int	get_inst_pos(char inst);
int	get_inst_size(char inst[3]);
int	get_inst_delay(char inst[3]);

/* gest_pc.c */
int	pc2int(unsigned char pc[2]);
void	inc_pc(unsigned char pc[2]);
void	dec_pc(unsigned char pc[2]);

/* vm_func.c */
void	read_in_mem(t_vm *vm);
void	waiting_for_nothing(t_vm *vm);
void	waiting_after(t_vm *vm);
void	now_just_execute(t_vm *vm);
void	are_they_alive(t_vm *vm);

/* vm_func2.c */
int	is_game_set(t_vm *vm);
int	step_by_step(t_vm *vm);
void	check_if_new_epoch(t_vm *vm);
void	the_winner_is(t_vm *vm, char **players);

#endif /* !VM_EXECUTE_H */
