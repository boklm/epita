/*
** cf.c for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 08:06:29 2002 nicolas vigier
** Last update Wed Dec  4 05:33:40 2002 nicolas vigier
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "listc.h"
#include "cf.h"
#include "readln.h"
#include "strutils.h"

/*
 * File format :
 * # comment
 * var = value
 * var = value #comment
 */

t_listc		*cf_read_file(char *file_name)
{
  int		fd;
  char		*ligne;
  char		*tmp;
  char		*comment;
  char		*value;
  t_config_val	*new_val;
  t_listc	*list;

  if ((fd = open(file_name, O_RDONLY)) == -1)
    return NULL;
  list = NULL;
  while ((ligne = readln(fd, '\n')))
    {
      tmp = remove_lspace(ligne);
      if (!*tmp || *tmp == '#')
	{
	  free(ligne);
	  continue ;
	}
      if ((value = strchr(tmp, '=')))
	{
	  new_val = malloc(sizeof (t_config_val));
	  *value++ = '\0';
	  if ((comment = strchr(value, '#')))
	    *comment = 0;
	  new_val->name = strdup(remove_rspace(tmp));
	  value = strdup(remove_rspace(remove_lspace(value)));
	  new_val->value = value;
	  list = listc_append(list, new_val);
	}
      free(ligne);
    }
  return list;
}

char		*cf_return_value(t_listc *list, char *name)
{
  t_config_val	*val;

  while (list)
    {
      val = list->data;
      if (val->name && !(strcmp(val->name, name)))
	return val->value;
      list = list->next;
    }
  return NULL;
}

void		cf_free(t_listc *list)
{
  t_config_val	*tmp;

  if (!list)
    return ;
  cf_free(list->next);
  tmp = list->data;
  free(tmp->name);
  free(tmp->value);
  free(tmp);
  free(list);
}
