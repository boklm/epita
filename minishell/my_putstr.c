/*
** my_putstr.c for piscine in /u/a1/vigier_n/c/rendu/piscine/j2
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Sep 24 21:57:10 2002 nicolas vigier
** Last update Mon Nov 18 21:15:42 2002 nicolas vigier
*/

#include "minishell.h"

void	my_putstr(const char *str)
{
  while (*str != '\0')
    my_putchar(*str++);
}
