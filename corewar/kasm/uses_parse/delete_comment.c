/*
** uses_parse.c for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Thu Dec  5 14:00:36 2002 olivier lecornet
** Last update Sun Dec 22 20:27:21 2002 nicolas vigier
*/

#include "uses_parse.h"

void	delete_comment(char *line)
{
  int	i, comment_find, in;

  for (in = 0, i = 0, comment_find = 0; line[i] && !comment_find; i++)
    {
      if (line[i] == '\"')
	in ^= 1;
      if (!in && (line[i] == '#'))
	{
	  comment_find = 1;
	  line[i] = '\0';
	}
    }
}
