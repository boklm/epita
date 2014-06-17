/*
** main.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Oct 16 16:40:35 2002 nicolas vigier
** Last update Wed Oct 23 07:27:24 2002 nicolas vigier
*/

#include <unistd.h>
#include "myls.h"

int	usage(int exitval)
{
  write(2, "usage: myls [-laRA] [fichier ...]\n",
	my_strlen("usage: myls [-laRA] [fichier ...]\n"));
  exit(exitval);
}

static void	free_fileinfos_long(t_file *file)
{
  free(file->name);
  free(file->link);
  free(file->filemode);
  free(file->owner);
  free(file->group);
  free(file->modifdatestr);
}

static void	free_fileinfos(t_file *file, int optflags)
{
  if (optflags & LSOPT_LONG)
    free_fileinfos_long(file);
  free(file);
}

int		ls_rep(char *repname, int optflags, int rec, char *begin_path)
{
  t_file		*list;
  char			*tmp;
  char			*save_rep;
  t_file		*prev;

  save_rep = getenv("PWD");
  list = makelist_rep(repname, optflags, rec);
  print_list(list, optflags);
  while (list)
    {
      if (list->rec)
	{
	  tmp = malloc(my_strlen(begin_path) + list->name_len + 2);
	  tmp = my_strcpy(tmp, begin_path);
	  tmp = my_strcat(tmp, "/");
	  tmp = my_strcat(tmp, list->name);
	  my_putchar('\n');
	  my_putstr(tmp);
	  my_putstr(":\n");
	  ls_rep(tmp, optflags, LSOPT_REC & optflags, tmp);
	  free(tmp);
	}
      prev = list;
      list = list->next;
      free_fileinfos(prev, optflags);
    }
  return 0;
}

int		ls_files(char *files[], int argc, int flags)
{
  t_file	*list;

  list = makelist_files(files, argc, flags);
  print_list(list, flags);
  while (list)
    {
      if (list->rec)
	{
	  if (argc > 1)
	    {
	      my_putchar('\n');
	      my_putstr(list->name);
	      my_putstr(":\n");
	    }
	  ls_rep(list->name, flags, LSOPT_REC & flags, list->name);
	}
      list = list->next;
    }
  return 0;
}

int	main(int argc, char *argv[])
{
  int		optflags;
  int		begin_files;

  optflags = getoptflags(argc, argv, &begin_files);
  if (begin_files < argc)
    return ls_files(argv + begin_files, argc - begin_files, optflags);
  else
    return ls_rep(".", optflags, optflags & LSOPT_REC, ".");
}
