/*
** help.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Mon Dec  2 01:33:19 2002 jean-yves tourtet
** Last update Tue Dec  3 22:00:49 2002 jean-yves tourtet
*/

#include <string.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "netutils.h"
#include "help.h"

void		help_prin(t_client *client, t_help help_cmd[], char *args)
{
  int		i, j;
  char		*cmd_help;
  
  j = 0;
  cmd_help = "\0";
  for (i = 0; help_cmd[i].cmd; ++i)
    {
      if (strcasecmp(help_cmd[i].cmd, args) == 0)
	{
	  cmd_help = help_cmd[i].cmd;
	  j = i;
	}
    }
  if (cmd_help != "\0")
    {
      send_msg2client(client, "214 Syntax : ");
      send_msg2client(client, help_cmd[j].syntax);
      send_msg2client(client, "\r\n");
    }
  else
    {
      send_msg2client(client, "502 Unknow command '");
      send_msg2client(client, args);
      send_msg2client(client, "'\r\n");
    }
}

void		help_func(t_client *client, char *args)
{
  t_help	help_cmd[] =
    {
      { "USER", "USER <SP> <username> <CRLF>" },
      { "PASS", "PASS <SP> <password> <CRLF>" },
      { "QUIT", "QUIT <CRLF>" },
      { "CWD", "CWD  <SP> <pathname> <CRLF>" },
      { "PWD", "PWD  <CRLF>" },
      { "LIST", "LIST [<SP> <pathname>] <CRLF>" },
      { "HELP", "HELP [<SP> <string>] <CRLF>" },
      { "STAT", "STAT [<SP> <pathname>] <CRLF>" },
      { "SYST", "SYST <CRLF>" },
      { "SIZE", "SIZE  <SP> <pathname> <CRLF>" },
      { "MKD", "MKD  <SP> <pathname> <CRLF>" },
      { "RMD", "RMD  <SP> <pathname> <CRLF>" },
      { "DELE", "DELE <SP> <pathname> <CRLF>" },
      { "STOR", "STOR <SP> <pathname> <CRLF>" },
      { "RETR", "RETR <SP> <pathname> <CRLF>" },
      { 0, 0 }
    };

  help_prin(client, help_cmd, args);
}
  
