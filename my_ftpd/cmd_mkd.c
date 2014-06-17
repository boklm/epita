/*
** cmd_mkd.c for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Wed Dec  4 04:50:07 2002 jean-yves tourtet
** Last update Wed Dec  4 05:26:57 2002 jean-yves tourtet
*/

#include <sys/stat.h>
#include <unistd.h>
#include "main_serv.h"
#include "serv_cl.h"
#include "cmd.h"
#include "netutils.h"
#include "strutils.h"
#include "utils.h"

void	cmd_mkd(t_ftpserv *ftpserv, t_client *client, char *args)
{
  char *pwd;

  CHECK_AUTH(client);
  pwd = xmalloc(sizeof (char) * 1024);
  args = remove_lspace(args);
  if (*args)
    {
      if (mkdir(args, 0705) == 0)
	  {
	    getcwd(pwd, 1024);
	    send_msg2client(client, "257 \"");
	    send_msg2client(client, pwd);
	    send_msg2client(client, "/");
	    send_msg2client(client, args);
	    send_msg2client(client, "\" directory created.\r\n");
	  }
    }
}
