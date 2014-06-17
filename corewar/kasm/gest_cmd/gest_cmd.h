/*
** gest_cmd.h for corewar in /u/a1/vigier_n/asm_new/asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Thu Dec 12 19:04:40 2002 nicolas vigier
** Last update Wed Dec 18 04:39:30 2002 nicolas vigier
*/

#ifndef GEST_CMD_H
# define GEST_CMD_H

/*
int		recup_register(t_info *info, t_cmd_list *newcmd,
			       t_word *word, int size);

int		recup_constant(t_info *info, t_cmd_list *newcmd,
			       t_word *word, int size);
*/

/*
int		tst_reg(t_info *all, t_cmd_list *newcmd,
			t_word *argcmd, int size);

int		tst_expr(t_info *all, t_cmd_list *newcmd,
			 t_word *argcmd, int size);
*/

int		test_cmd(t_info *info, t_word **argcmd);

t_cmd_list	*init_cmdlist(void);

t_cmd_list	*add_cmdlist(t_cmd_list *list, t_cmd_list *new);

#endif /* GEST_CMD_H */
