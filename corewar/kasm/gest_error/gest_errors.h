/*
** gest_error.h for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec 11 09:57:31 2002 olivier lecornet
** Last update Sun Dec 22 11:30:59 2002 nicolas vigier
*/

#ifndef GEST_ERRORS_H
# define GEST_ERRORS_H

# include "../asm.h"
# include "macro_err.h"
# include "aff_errors.h"
# include "aff_one_err.h"
# include "warn_miss_dir.h"

typedef struct	s_aff_error
{
  int		type;
  void		(*aff_err) (t_error *, char *, char *, char *);
  char		*pref;
  char		*med;
  char		*suf;
}		t_aff_error;

t_error	*add_error(t_error *tete, char *msg, int type, int line);
t_error	*add_error_sorted(t_error *tete, char *msg, int type, int line);
t_error	*append_t_error(t_error	*tete, t_error *node);


#endif /* GEST_ERRORS_H */
