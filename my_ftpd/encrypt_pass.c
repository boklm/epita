/*
** encrypt_pass.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Sat Nov 30 23:49:31 2002 jean-yves tourtet
** Last update Tue Dec  3 21:35:55 2002 jean-yves tourtet
*/

#include <stdio.h>
#include <unistd.h>

char	*crypt_pass(char *arg)
{
  char	*pass;

  if (arg)
    {
      pass = crypt(arg, "Xq");
      return pass;
    }
  else
    {
      pass = 0;
      return pass;
    }
}
