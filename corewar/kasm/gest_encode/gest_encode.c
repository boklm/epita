/*
** gest_encode.c for corewar in /home/boklm/asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Dec 16 15:26:01 2002 nicolas vigier
** Last update Sun Dec 22 13:40:34 2002 nicolas vigier
*/

#include "../asm.h"
#include "gest_encode.h"

static char	setieme(char c, int i)
{
  int		mask;

  mask = 1;
  while (i--)
    mask = mask * 2;
  return c | mask;
}

static char	encode_cmd(char *cmd, char *line)
{
  int		size_line;
  int		i;
  char		res;

  res = 0;
  size_line = my_strlen(line);
  for (i = 0; i < 4; i++)
    {
      if (cmd[i] == '1' || (cmd[i] != '0' && i < size_line &&
			    my_isupper(line[i])))
	res = setieme(res, i);
    }
  return res;
}

static void	encode(t_info *all, t_cmd_list *cmd)
{
  t_cmd		*cmd_info;

  cmd_info = cmd->cmd_info;
  all->size_prog += cmd_info->size_cmd;
  cmd->cmd[0]->size = cmd_info->size_cmd - cmd_info->nb_quartets_arg1 -
    cmd_info->nb_quartets_arg2;
  cmd->cmd[0]->codage = xmalloc(cmd->cmd[0]->size);
  if (cmd->cmd[0]->size == 1)
    cmd->cmd[0]->codage[0] = encode_cmd(cmd_info->codage_cmd,
					cmd->cmd[0]->word);
  else
    {
      cmd->cmd[0]->codage[0] = encode_cmd(cmd_info->codage_cmd,
					  cmd->cmd[0]->word);
      cmd->cmd[0]->codage[1] = encode_cmd(cmd_info->codage_cmd + 4, "");
    }
  if (cmd_info->func_ncod_arg1)
    cmd_info->func_ncod_arg1(all, cmd, cmd->cmd[1], cmd_info->nb_quartets_arg1);
  if (cmd_info->func_ncod_arg2)
    cmd_info->func_ncod_arg2(all, cmd, cmd->cmd[2], cmd_info->nb_quartets_arg2);
}

int		gest_encode(t_info *all)
{
  t_cmd_list	*list;

  list = all->tete_cmd;
  while (list)
    {
      if (list->pure_code)
	recup_pure_code(all, list);
      else
	encode(all, list);
      list = list->next;
    }
  return 1;
}
