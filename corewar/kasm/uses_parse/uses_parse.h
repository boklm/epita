/*
** uses_parse.h for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Mon Dec  9 18:57:37 2002 olivier lecornet
** Last update Tue Dec 10 16:27:22 2002 olivier lecornet
*/

#ifndef USES_PARSE_H
# define USES_PARSE_H

#include "../asm.h"

char    *next_word(char *line);
int     is_space(char c);
char    *isolate_word(t_info *all, char **line);
void    delete_comment(char *line);
void	delete_end_spaces(char *line);

#endif /* USES_PARSE_H */
