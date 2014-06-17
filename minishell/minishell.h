/*
** minishell.h for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Mon Nov 18 10:44:24 2002 nicolas vigier
** Last update Wed Nov 20 03:14:11 2002 nicolas vigier
*/

#include <unistd.h>
#include "my_strlen.h"
#include "my_strncmp.h"

#define ERR_PARS	"/!\\ Pars error\n"
#define ERR_PIPE	"/!\\ Pipe error\n"
#define ERR_FILE	"/!\\ File access error\n"
#define ERR_FORK	"/!\\ Fork error\n"
#define ERR_PIPE	"/!\\ Pipe error\n"
#define ERR_MALLOC	"/!\\ Malloc error\n"
#define ERR_DL		"/!\\ load error\n"

#define READLN_SIZE	30

struct	s_str
{
  char	*str;
  char	*ptr;
  int	size;
};
typedef struct s_str	t_str;

struct	s_lst
{
  void		*ptr;
  struct s_lst	*next;
};
typedef struct s_lst t_lst;

struct	s_shell
{
  char	*execname;
  int	noexit;
  t_lst	*list_modules;
};
typedef struct s_shell	t_shell;

struct	s_prg
{
  char	**args;
  t_lst	*list_args;
  int	outfd;
  int	infd;
  char	*infile;
  char	*outfile;
  int	appendfile;
  int	async;
  char	*ptr;
};
typedef struct s_prg	t_prg;

struct	s_bt
{
  char	*name;
  int	name_size;
  void	*dh;
  int	type;
};
typedef struct s_bt	t_bt;

void	error_msg(char *msg);
void	exit_perror(char *str);
void	exit_error(char *str);
t_prg	*new_prg(void);
int	pars_exec_cmd(t_shell *shell, char *str, t_prg *prg, int fork);

int	do_pipe(t_shell *shell, t_prg *prg);
int	do_or(t_shell *shell, t_prg *prg);
int	do_and(t_shell *shell, t_prg *prg);

int	exec_prg(t_shell *shell, t_prg *prg);
int	forknexec_prg(t_shell *shell, t_prg *prg);

void	*mmalloc(size_t size);

char		*my_strncpy(char *dest, const char *src, int n);
unsigned int	my_strlen(const char *str);
char		*my_strndup(const char *src, int n);

char	*readln(void);

int	prompt(t_shell *shell);
void	my_putchar(char c);
void	my_putstr(const char *str);

t_lst	*lst_add_elt(t_lst *lst, void *newptr);
int	check_bt(t_shell *shell, t_prg *prg, int nofork);
int	check_load(t_shell *shell, t_prg *prg);
