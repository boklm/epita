/*
** add_user_db.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Tue Dec  3 00:26:29 2002 jean-yves tourtet
** Last update Wed Dec  4 00:56:20 2002 jean-yves tourtet
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my_tools.h"
#include "utils.h"
#include "encrypt_pass.h"
#include "error.h"
#include "write_out.h"

void	create_user_db(char *username, char *crypt_passwd, char *homedirectory)
{
  char	*c, *data;
  int	i, fd, length, length1, length2, length3;

  c = "\n";
  length1 = my_strlen(username);
  length2 = my_strlen(crypt_passwd);
  length3 = my_strlen(homedirectory);
  length = length1 + length2 + length3 + 2;
  data = xmalloc(sizeof (char) * length);
  for (i = 0; i < length1; i++)
    data[i] = username[i];
  data[length1] = ':';
  for (i = length1 + 1; i < length1 + length2 + 1; i++)
    data[i] = crypt_passwd[i - length1 - 1];
  data[length1 + length2 + 1] = ':';
  for (i = length1 + length2 + 2; i < length; i++)
    data[i] = homedirectory[i - length1 - length2 - 2];
  if ((fd = open("users.db", O_WRONLY | O_APPEND)) == -1)
    exit_perror("open");
  if (write(fd, data, length) == -1)
    exit_perror("write");
  if (write(fd, c, 1) == -1)
    exit_perror("write");
  close(fd);
}

void	add_user_db(char *username, char *passwd, char *homedirectory)
{
  char	*crypt_passwd;

  if ((!(*username)) || (!(*passwd)) || (!(*homedirectory)))
    {
      write_stdout("<missing one or several arguments>\n");
      exit(1);
    }
  crypt_passwd = crypt_pass(passwd);
  if (my_strcmp(crypt_passwd, "") == 0)
    {
      write_stdout("<invalid argument>\n");
      exit(1);
    }
  create_user_db(username, crypt_passwd, homedirectory);
}

int	main(int argc, char **argv)
{
  char	c, *user, *pwd, *homedir;

  user = "\0";
  pwd = "\0";
  homedir = "\0";
  write_stdout("\n\t**ADD A USER IN DATABANK**\n\n");
  write_stdout("<enter your login>\n");
  while ((read(STDIN_FILENO, &c, 1) != -1) && (c != '\n'))
    user = my_strconcat(user, c);
  write_stdout("<enter your password>\n");
  while ((read(STDIN_FILENO, &c, 1) != -1) && (c != '\n'))
    pwd = my_strconcat(pwd, c);
  write_stdout("<enter your homedirectory>\n");
  while ((read(STDIN_FILENO, &c, 1) != -1) && (c != '\n'))
    homedir = my_strconcat(homedir, c);
  add_user_db(user, pwd, homedir);
  write_stdout("<you are now a member of our databank>\n");
  return 0;
}
