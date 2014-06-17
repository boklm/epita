/*
** list.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Oct 20 15:18:59 2002 nicolas vigier
** Last update Wed Oct 23 07:19:37 2002 nicolas vigier
*/

#include "myls.h"

static t_dir	*init_dirinfos(t_file *file)
{
  t_dir		*dirinfos;

  dirinfos = malloc(sizeof (t_dir));
  if (file->is_dir)
    dirinfos->nbrep = 1;
  else
    dirinfos->nbrep = 0;
  dirinfos->total_blocks = file->blocks;
  dirinfos->file_max_len = file->name_len;
  dirinfos->nb_elts = 1;
  return dirinfos;
}

static void	update_dirinfos(t_file *file)
{
  t_dir		*dirinfos;

  dirinfos = file->dirinfos;
  dirinfos->nb_elts++;
  if (file->is_dir)
    dirinfos->nbrep++;
  if (file->name_len > dirinfos->file_max_len)
      dirinfos->file_max_len = file->name_len;
  dirinfos->total_blocks += file->blocks;
}

t_file	*list_insert_sorted(t_file *list, t_file *new,
			    int (*func)
			    (const t_file *, const t_file *))
{
  t_file	*prev;
  t_file	*list_save;

  list_save = list;
  prev = NULL;
  while (list && ((func)(new, list) > 0))
    {
      prev = list;
      list = list->next;
    }
  new->next = list;
  if (prev)
    {
      new->dirinfos = prev->dirinfos;
      prev->next = new;
    }
  else
    {
      new->dirinfos = (list) ? list->dirinfos : init_dirinfos(new);
      return new;
    }
  update_dirinfos(new);
  return list_save;
}
