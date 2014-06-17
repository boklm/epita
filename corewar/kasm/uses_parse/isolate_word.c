/*
** isolate_word.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Mon Dec  9 18:52:03 2002 olivier lecornet
** Last update Fri Dec 20 13:22:55 2002 olivier lecornet
*/

#include "uses_parse.h"

char	*without_quotes(char **line)
{
  char	*res;
  int	len, i;

  for (len = 0; (!is_space((*line)[len])) &&
	 ((*line)[len] != ',') &&
	 ((*line)[len] != ']'); len++) ;
  if (((*line)[len] == ',') || ((*line)[len] == ']'))
     len++;
  res = xmalloc(sizeof (char) * len + 2);
  for (i = 0; i < len; i++)
    res[i] = (*line)[i];
  if ((*line)[len])
    *line = &((*line)[len]);
  else
    *line = NULL;
  res[i] = '\0';
  return (res);
}

char	*with_quotes(t_info *all, char **line, int len, char *res)
{
  char	*tmp;

  while ((*line)[len] != '\"')
    {
      if (((*line)[len] == '\0'))
	{
	  (*line)[len] = '\n';
	  tmp = my_strncpy(*line, len + 1);
	  res = my_strcat(res, tmp);
	  *line = getln(all);
	  len = 0;
	  all->line++;
	  if (*line == NULL)
	    return (res);
	}
      else
	len++;
    }
  tmp = my_strncpy(*line, len + 1);
  res = my_strcat(res, tmp);
  if ((*line)[len + 1] != '\0')
    *line = &((*line)[len + 1]);
  else
    *line = NULL;
  return (res);
}

char	*isolate_word(t_info *all, char **line)
{
  int	len;
  char	*res;

  len = 1;
  if ((*line)[0] == '\"')
    res = with_quotes(all, line, len, NULL);
  else
    res = without_quotes(line);
  return (res);
}
