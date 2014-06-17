/*
** compare_func.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Sun Oct 20 15:56:04 2002 nicolas vigier
** Last update Sun Oct 20 15:58:13 2002 nicolas vigier
*/

#include "myls.h"

int	compare_str(const t_file *file1, const t_file *file2)
{
  return my_strcmp(file1->name, file2->name);
}
