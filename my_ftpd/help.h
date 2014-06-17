/*
** help.h for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Mon Dec  2 02:25:46 2002 jean-yves tourtet
** Last update Tue Dec  3 22:01:36 2002 jean-yves tourtet
*/

#ifndef HELP_H
#define HELP_H

typedef struct	s_help
{
  char		*cmd;
  char		*syntax;
}			t_help;

void help_func(t_client *client, char *args);
void		help_prin(t_client *client, t_help help_cmd[], char *args);

#endif /* !HELP_H */
