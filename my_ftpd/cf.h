/*
** cf.h for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 08:08:14 2002 nicolas vigier
** Last update Tue Dec  3 08:56:30 2002 nicolas vigier
*/

struct	s_config_val
{
  char	*name;
  char	*value;
};
typedef struct s_config_val	t_config_val;

t_listc	*cf_read_file(char *file_name);
char	*cf_return_value(t_listc *list, char *name);
void	cf_free(t_listc *list);
