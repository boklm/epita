/*
** print.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Fri Oct 18 14:16:32 2002 nicolas vigier
** Last update Wed Oct 23 07:17:33 2002 nicolas vigier
*/

#include <unistd.h>
#include "myls.h"

static void	print_size(t_file *file)
{
  if (file->specfile)
    {
      my_putchar(' ');
      my_putnbr_alignr(file->major, 3);
      my_putchar(',');
      my_putnbr_alignr(file->minor, 4);
      my_putchar(' ');
    }
  else
    {
      my_putchar(' ');
      my_putnbr_alignr(file->filesize, 8);
      my_putchar(' ');
    }
}

static int	print_elt_long(t_file *list, int optflags)
{
  if (!list->showfile)
    return 0;
  my_putstr(list->filemode);
  my_putchar(' ');
  my_putnbr_alignr(list->nblinks, 4);
  my_putchar(' ');
  if (list->owner)
    my_putstr_alignl(list->owner, 8);
  else
    my_putnbr_alignl(list->uid, 8);
  my_putchar(' ');
  if (list->group)
    my_putstr_alignl(list->group, 8);
  else
    my_putnbr_alignl(list->gid, 8);
  print_size(list);
  my_putstr(list->modifdatestr);
  my_putchar(' ');
  my_putstr(list->name);
  return 1;
}

static void	print_list_long(t_file *list, int optflags)
{
  if (list)
    {
      my_putstr("total ");
      my_putnbr(list->dirinfos->total_blocks / 2);
      my_putchar('\n');
    }
  while (list)
    {
      if (!print_elt_long(list, optflags))
	{
	  list = list->next;
	  continue ;
	}
      if (list->link)
	{
	  my_putstr(" -> ");
	  my_putstr(list->link);
	}
      my_putchar('\n');
      list = list->next;
    }
}

static void	print_list_nocolumns(t_file *list, int optflags)
{
  while (list)
    {
      if (list->showfile)
	{
	  my_putstr(list->name);
	  my_putchar('\n');
	}
      list = list->next;
    }
}

static void	print_list_columns(t_file *list, int optflags)
{
  print_list_nocolumns(list, optflags);
}

void	print_list(t_file *list, int optflags)
{
  if (!list)
    return ;
  if (optflags & LSOPT_LONG)
    print_list_long(list, optflags);
  else if (isatty(1) || (LSOPT_C & optflags))
    print_list_columns(list, optflags);
  else
    print_list_nocolumns(list, optflags);
}
