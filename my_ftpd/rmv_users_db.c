/*
** rmv_users_db.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Tue Dec  3 17:07:38 2002 jean-yves tourtet
** Last update Wed Dec  4 03:46:53 2002 jean-yves tourtet
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my_tools.h"
#include "error.h"
#include "write_out.h"


static void	one_to_line(char c, int fd, int fd2)
{
  while (c != '\n')
    {
      if (read(fd, &c, 1) == -1)
	  exit_perror("read");
      if (write(fd2, &c, 1) == -1)
	exit_error("write");
      }
}

static void	before_line(char c, int fd, int fd2)
{
  while (c != '\n')
    {
      if (read(fd, &c, 1) == -1)
	exit_perror("read");
      if (write(fd2, &c, 1) == -1)
	exit_error("write");
    }
  if (read(fd, &c, 1) == -1)
    exit_perror("read");
  if (write(fd2, &c, 1) == -1)
    exit_error("write");
}

static void	rmv_line(int nb_lines)
{
  char		c;
  int		i, fd, fd2;

  c = '\0';
  i = 1;
  if ((fd = open("users.db", O_RDWR, 0666)) == -1)
    exit_perror("open");
  if ((fd2 = open("user_tmp", O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
    exit_perror("open");
  while (i < nb_lines - 1)
    {
      before_line(c, fd, fd2);
      i++;
    }
  if (nb_lines != 1)
    one_to_line(c, fd, fd2);
  c ='\0';
  while (c != '\n')
    if (read(fd, &c, 1) == -1)
      exit_perror("read");
  while (read(fd, &c, 1) != 0)
    if (write(fd2, &c, 1) == -1)
      exit_perror("write");
  close(fd);
  close(fd2);
}

static void	rmv(int fd, char *user_db, char *username, int nb_lines)
{
  char		c;

  if (my_strcmp(user_db, username) != 0)
    {
      c = ':';
      while ((c != '\n') && (c != '\0'))
	{
	  if (read(fd, &c, 1) == -1)
	    exit_perror("read");
	}
    }
  else
    {
      close(fd);
      rmv_line(nb_lines);
    }
}

static void	find_username(int fd, char *username)
{
  int		eol, nb_lines;
  char		c, *user_db;

  eol = 0;
  nb_lines = 1;
  user_db = "\0";
  while (((eol = read(fd, &c, 1)) != 0) &&
	 (my_strcmp(user_db, username) != 0))
    {
      user_db = "\0";
      user_db = my_strconcat(user_db, c);
      while ((read(fd, &c, 1) != 0) && (c != ':') && (c != '\n'))
	user_db = my_strconcat(user_db, c);
      rmv(fd, user_db, username, nb_lines);
      nb_lines += 1;
    }
  if ((eol == 0) && (my_strcmp(user_db, username) != 0))
    {
      write_stdout("<we don't find ");
      write_stdout(username);
      write_stdout(" in our databank>\n");
      exit(1);
    }
}

static void	rmv_users_db(char *username)
{
  int		fd;

  if (!(*username))
    {
      write_stdout("<missing argument>\n");
      exit(1);
    }
   if ((fd = open("users.db", O_RDWR, 0666)) == -1)
     exit_perror("open");
   find_username(fd, username);
   close(fd);
}

int		main(int argc, char **argv)
{
  char		c, *user;

  user = "\0";
  write_stdout("\n\t**REMOVE A USER IN DATABANK**\n\n");
  write_stdout("<enter the login of the user you want to remove>\n");
  while ((read(STDIN_FILENO, &c, 1) != -1) && (c != '\n'))
    user = my_strconcat(user, c);
  rmv_users_db(user);
  write_stdout("< ");
  write_stdout(user);
  write_stdout(" was removed of our databank>\n");
  rename("user_tmp", "users.db");
  return 0;
}
