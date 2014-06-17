/*
** my_strcat.h for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Mon Dec  9 15:23:43 2002 olivier lecornet
** Last update Sun Dec 22 13:10:48 2002 nicolas vigier
*/

#ifndef USES_STR_H
# define USES_STR_H

# include "my_putchar.h"
# include "my_putstr.h"
# include "my_putnbr.h"
# include "my_putstrstr.h"
# include "my_putstrnbr.h"
# include "../asm.h"
# include "my_system.h"
# include "../my_struct.h"

char    *my_strcat(char *s1, char *s2);
char	*my_strdup(char *src);
char	*my_strcpy(char *dst, const char *src);
char	*my_strncpy(char *src, int n);
int	my_strlen(char *s);
int	my_strncmp(char *s1, char *s2, int n);
int	my_strcasecmp(char *str1, char *str2);
int	my_strcmp(char *s1, char *s2);
char	*getln(t_info *all);
int	my_isdigit(char c);
int	my_isupper(char c);
int	my_tolower(int c);

#endif /* USES_STR_H */
