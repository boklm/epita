/*
** myls.h for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Oct 16 16:41:23 2002 nicolas vigier
** Last update Wed Oct 23 07:13:43 2002 nicolas vigier
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>

#define LSOPT_LONG	1
#define LSOPT_ALL	4
#define LSOPT_REC	8
#define LSOPT_A		16
#define LSOPT_C		32

struct		s_dir
{
  int		nbrep;
  int		total_blocks;
  int		file_max_len;
  int		nb_elts;
};
typedef struct s_dir	t_dir;

struct			s_file
{
  int			showfile;
  int			rec;
  int			is_dir;
  char			*name;
  char			*link;
  int			name_len;
  char			*filemode;
  off_t			filesize;
  int			blocks;
  nlink_t		nblinks;
  char			*owner;
  int			uid;
  char			*group;
  int			gid;
  int			minor;
  int			major;
  int			specfile;
  struct tm		*modifdate;
  char			*modifdatestr;
  struct s_dir		*dirinfos;
  struct s_file		*next;
};
typedef struct s_file	t_file;

struct		s_filepath
{
  char		*filename;
  const char	*path;
};

void		my_putchar(char c);
void		my_putstr(const char *str);
unsigned int	my_strlen(const char *str);
int		my_strcmp(const char *s1, const char *s2);
int		my_strncmp(const char *s1, const char *s2, int n);
char		*my_strdup(char *str);
int		usage(int exitval);
int		getoptflags(int argv, char *argvc[], int *place);
t_file		*makelist_rep(const char *reppath, int flags, int rec);
t_file		*makelist_files(char *files[], int argv, int flags);
int		compare_str(const t_file *file1, const t_file *file2);
t_file		*list_insert_sorted(t_file *list, t_file *new,
				    int (*func)(const t_file *, const t_file *));
void		print_list(t_file *list, int optflags);
char		*my_strcpy(char *dest, const char *src);
char		*my_strcat(char *dest, const char *src);
void		my_putstr_alignr(const char *str, int size);
void		my_putstr_alignl(const char *str, int size);
void    	my_putnbr(int nbr);
void		my_putnbr_alignl(int nbr, int size);
void		my_putnbr_alignr(int nbr, int size);
int		my_atoi(const char *str);
char		*concatpath(const char *rep, const char *fname);
