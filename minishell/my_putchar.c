/*
** my_putchar.c for piscine in /u/prof/acu/www/sujets/piscine
**
** Made by assistant c unix
** Login   <acu@epita.fr>
**
** Started on  Sun Sep 22 23:52:11 2002 assistant c unix
** Last update Mon Nov 18 21:15:22 2002 nicolas vigier
*/

#include <unistd.h>
#include "minishell.h"

void	my_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}
