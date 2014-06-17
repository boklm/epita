/*
** getln.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec  4 14:54:54 2002 olivier lecornet
** Last update Fri Dec 20 05:39:06 2002 nicolas vigier
*/

#include "uses_str.h"

static int	complete_buf(t_info *all)
{
  all->size_buf = my_read(all->fd_input, all->str_buf, MY_BUF_SIZE);
  if (all->size_buf == 0)
    return (0);
  all->pos_buf = 0;
  return (1);
}

char	*getln(t_info *all)
{
  int	init;
  char	*tmp, *tmp2, *res;

  if (all->pos_buf >= all->size_buf)
    if (!complete_buf(all))
      return (NULL);
  for (init = all->pos_buf; (all->pos_buf <= all->size_buf) &&
	 (all->str_buf[all->pos_buf] != '\n'); (all->pos_buf)++) ;
  if (all->str_buf[all->pos_buf] == '\n')
    {
      all->pos_buf++;
      all->str_buf[all->pos_buf - 1] = 0;
      tmp = my_strdup(&(all->str_buf[init]));
      return (tmp);
    }
  tmp = my_strdup(&(all->str_buf[init]));
  tmp2 = getln(all);
  res = my_strcat(tmp, tmp2);
  free(tmp);
  free(tmp2);
  return (res);
}
