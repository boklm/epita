/*
** test_cmd.c for corewar in /u/a1/vigier_n/corewar/corewar_asm/corewar_asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec 10 13:00:20 2002 nicolas vigier
** Last update Sun Dec 22 19:10:59 2002 nicolas vigier
*/

#include "../asm.h"
#include "gest_cmd.h"

static int	test_arg(t_info *info, t_word *cmd, t_word *test)
{
  if (!test)
    {
      info->tete_error = add_error(info->tete_error, cmd->word,
				   ERR_FEW_ARGUMENT, cmd->line);
      info->do_encode = 0;
      return 0;
    }
  return 1;
}

void		concat_num(t_word *tete)
{
  while (tete->next)
    if (((is_op(tete->next->word[0])) ||
	 (is_op(tete->word[my_strlen(tete->word) - 1]))) &&
	(tete->word[my_strlen(tete->word) - 1] != ','))
      {
	tete->word = my_strcat(tete->word, tete->next->word);
	tete->next = tete->next->next;
      }
    else
      return ;
}

static void	recup_arg1(int i, t_cmd_list *newcmd, t_word **argcmd)
{
  newcmd->cmd[1] = *argcmd;
  newcmd->size += cmds[i].nb_quartets_arg1;
  if (cmds[i].func_ncod_arg1 == recup_constante)
    concat_num(*argcmd);
  *argcmd = (*argcmd)->next;
}

static void	recup_arg2(int i, t_cmd_list *newcmd, t_word **argcmd)
{
  newcmd->cmd[2] = *argcmd;
  newcmd->size += cmds[i].nb_quartets_arg2;
  if (cmds[i].func_ncod_arg2 == recup_constante)
    concat_num(*argcmd);
  *argcmd = (*argcmd)->next;
}

int		test_cmd(t_info *info, t_word **argcmd)
{
  int		i;
  t_cmd_list	*newcmd;

  for (i = 0; i < NB_CMDS - 1; i++)
    if (!my_strcasecmp((*argcmd)->word, cmds[i].cmd))
      {
	actualise_before_label(info);
	actualise_before_label_2(info);
	newcmd = init_cmdlist();
	newcmd->cmd_info = cmds + i;
	*newcmd->cmd = *argcmd;
	newcmd->size = cmds[i].size_cmd - cmds[i].nb_quartets_arg1 - cmds[i].nb_quartets_arg2;
	*argcmd = (*argcmd)->next;
	info->tete_cmd = add_cmdlist(info->tete_cmd, newcmd);
	if (cmds[i].func_ncod_arg1)
	  while (*argcmd && test_label(info, argcmd))
	    ;
	if (cmds[i].func_ncod_arg1 && (test_arg(info, newcmd->cmd[0], *argcmd)))
	  recup_arg1(i, newcmd, argcmd);
	if (cmds[i].func_ncod_arg2)
	  while (*argcmd && test_label(info, argcmd))
	    ;
	if (cmds[i].func_ncod_arg2 && (test_arg(info, newcmd->cmd[0], *argcmd)))
	  recup_arg2(i, newcmd, argcmd);
	return 1;
      }
  return 0;
}
