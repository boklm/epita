/*
** pass_ident.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Sun Dec  1 20:40:22 2002 jean-yves tourtet
** Last update Tue Dec  3 21:21:47 2002 jean-yves tourtet
*/

#include <unistd.h>
#include "my_tools.h"
#include "main_serv.h"
#include "serv_cl.h"
#include "pass_ident.h"

static int test_passwd(char *arg)
{
  if (*arg == '\0')
    return 0;
  return 1;
}

static t_client	*passwd_st(int i, t_client *motsuc,
			   char *pass)
{
  int		j;
  char		*homedir;

  homedir = "\0";
  j = 0;
  while (motsuc->homedirectory[i + 1 + j] != '\0')
    {
      homedir = my_strconcat(homedir,
			     motsuc->homedirectory[i + 1 + j]);
      j++;
    }
  motsuc->passwd = pass;
  motsuc->homedirectory = homedir;
  return motsuc;
}

t_client	*pass_ident(t_client *motsuc)
{
  int		i;
  char		*pass, *egpass;

  i = 0;
  pass = "\0";
  if (test_passwd(motsuc->passwd) == 0)
    {
      motsuc = 0;
      return motsuc;
    }
  egpass = crypt(motsuc->passwd, "Xq");
  while (motsuc->homedirectory[i] != ':')
    {
      pass = my_strconcat(pass, motsuc->homedirectory[i]);
      i++;
    }
  if (my_strcmp(egpass, pass) != 0)
    motsuc = 0;
  else
    motsuc  = passwd_st(i, motsuc, pass);
  return motsuc;
}
