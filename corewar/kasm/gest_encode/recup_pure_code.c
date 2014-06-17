/*
** recup_pure_code.c for corewar in /u/a1/vigier_n/corewar/kasm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sat Dec 21 11:53:02 2002 nicolas vigier
** Last update Sun Dec 22 13:41:06 2002 nicolas vigier
*/

#include "../asm.h"

static char	code_value(char c)
{
  if (c >= '0' && c <= '9')
    return c - '0';
  if (c >= 'A' && c <= 'F')
    return 10 + c - 'A';
  return 10 + c - 'a';
}

int		recup_pure_code(t_info *info, t_cmd_list *cmdlist)
{
  t_word	*cmd;
  int		i;

  cmd = *cmdlist->cmd;
  cmd->size = my_strlen(cmd->word);
  info->size_prog += cmd->size;
  cmd->codage = xmalloc(cmd->size);
  for (i = 0; i < cmd->size; i++)
    cmd->codage[i] = invert_quartet(code_value(cmd->word[i]));
  return 1;
}
