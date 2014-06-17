/*
** gest_inst.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:47:23 2002 eric augustin
** Last update Sun Dec 22 15:47:26 2002 eric augustin
*/
#include "tab.h"

int		get_inst_pos(char inst)
{
  int		i;
  int		oki;
  unsigned char	tmp;

  for (i = oki = 0; i < NB_CMDS && !oki; i++)
  {
    tmp = inst;
    if (cmds[i].sig1)
      tmp &= 0x7f;
    if (cmds[i].sig2)
      tmp &= 0xf7;
    if (cmds[i].size_inst == 1)
      tmp |= 0x0f;
    if (tmp == cmds[i].code)
      oki = 1;
  }
  return (i - 1);
}

int	get_inst_size(char inst[3])
{
  int	i;

  i = get_inst_pos(inst[0]);
  return (cmds[i].size);
}

int	get_inst_delay(char inst[3])
{
  int	i;

  i = get_inst_pos(inst[0]);
  return (cmds[i].delay);
}

