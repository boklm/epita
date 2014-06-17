/*
** listc.h for my_ftpd in /u/a1/vigier_n/c/rendu/mp/my_ftpd
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec  3 08:05:20 2002 nicolas vigier
** Last update Tue Dec  3 08:36:12 2002 nicolas vigier
*/

struct			s_listc
 {
  struct s_listc	*prev;
  void			*data;
  struct s_listc	*next;
};
typedef struct s_listc	t_listc;

t_listc	*listc_append(t_listc *list, void *new_val);
t_listc	*listc_preppend(t_listc *list, void *new_val);
