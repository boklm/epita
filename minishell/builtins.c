/*
** builtins.c for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Nov 19 13:07:26 2002 nicolas vigier
** Last update Wed Nov 20 05:26:50 2002 nicolas vigier
*/

#include <stdlib.h>
#include <dlfcn.h>
#include "minishell.h"

static t_bt	*new_bt(void *dh, char *name, int type)
{
  t_bt		*res;

  res = malloc(sizeof (t_bt));
  res->name = name;
  res->name_size = my_strlen(name);
  res->dh = dh;
  res->type = type;
  return res;
}

static int	exec_load(t_shell *shell, char **argv)
{
  void		*dh;
  char		*name;
  int		type;
  char		*(*fun)(void);
  int		(*fun2)(void);

  if (!argv[1] || !(dh = dlopen(argv[1], 0))
      || !(fun = dlsym(dh, "bt_name"))
      || !(fun2 = dlsym(dh, "bt_type")))
    {
      error_msg(ERR_DL);
      return -1;
    }
  name = fun();
  type = fun2();
  shell->list_modules = lst_add_elt(shell->list_modules,
				    new_bt(dh, name, type));
  return 1;
}

static t_bt	*find_bt(t_lst *lst, char *btname, int nofork)
{
  int		size;
  t_bt		*ptr;

  size = my_strlen(btname);
  while (lst)
    {
      ptr = lst->ptr;
      if ((!nofork || ptr->type) &&
	  (ptr->name_size == size) &&
	  (!my_strncmp(ptr->name, btname, size)))
	return ptr;
      lst = lst->next;
    }
  return NULL;
}

static int	exec_unload(t_shell *shell, char **argv)
{
  t_bt		*tmp;

  tmp = find_bt(shell->list_modules, argv[1], 0);
  if (tmp)
    {
      tmp->name = "";
      tmp->name_size = -1;
      dlclose(tmp->dh);
      return 1;
    }
  return 0;
}

int	check_load(t_shell *shell, t_prg *prg)
{
  int	res;

  if ((my_strlen(prg->args[0]) == 4) && !(my_strncmp(prg->args[0], "load", 4)))
    {
      res = exec_load(shell, prg->args);
      return 1;
    }
  if ((my_strlen(prg->args[0]) == 6) && !(my_strncmp(prg->args[0], "unload", 6)))
      return exec_unload(shell, prg->args);
  return -1;
}

int	check_bt(t_shell *shell, t_prg *prg, int nofork)
{
  t_bt	*bt;
  int	res;
  int	(*fun)(char **args);

  if (!(bt = find_bt(shell->list_modules, prg->args[0], nofork)))
    return -1;
  fun = dlsym(bt->dh, "exec_bt");
  res = fun(prg->args);
  if (nofork)
    return res;
  exit(res);
  return 1;
}
