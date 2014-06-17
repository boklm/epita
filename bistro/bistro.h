/*
** bistro.h for bistro in /u/a1/vigier_n/bistro/my_bistro
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Thu Oct 31 14:40:02 2002 nicolas vigier
** Last update Sun Nov 10 12:37:18 2002 bruno legros
*/

#ifndef BISTRO_H
# define BISTRO_H

# include <unistd.h>
# include <stdlib.h>
# include "errors.h"

# define IS_EMP(A, B) (A == B->op_emp)
# define IS_ECH(A, B) (A == B->op_ech)
# define IS_NEG(A, B) (A == B->op_neg)
# define IS_ADD(A, B) (A == B->op_add)
# define IS_SUB(A, B) (A == B->op_sub)
# define IS_MUL(A, B) (A == B->op_mul)
# define IS_DIV(A, B) (A == B->op_div)
# define IS_DIVENT(A, B) (A == B->op_divent)
# define IS_GRP_BEG(A, B) (A == B->op_grp_beg)
# define IS_GRP_END(A, B) (A == B->op_grp_end)

# define EXPR_RPN	1
# define EXPR_INFIX	2
# define SIZE		1024

typedef struct	s_base
{
  char		*base;
  int		base_len;
}		t_base;

typedef struct	s_nbr
{
  char		*nbr;
  int		nbr_len;
  char		*frac;
  int		frac_len;
  int		negative;
  int		makefree;
  t_base	*base;
}		t_nbr;

typedef struct	s_bistro
{
  t_base	*base;
  char		op_emp;
  char		op_ech;
  char		op_neg;
  char		op_add;
  char		op_sub;
  char		op_mul;
  char		op_div;
  char		op_divent;
  char		op_grp_beg;
  char		op_grp_end;
  char		*expr;
  char		*end_expr;
  int		expr_len;
  int		expr_cursor;
  char		form;
  int		type;
}		t_bistro;

typedef struct	s_pile
{
  t_nbr		*elt;
  struct s_pile	*next;
}		t_pile;

typedef struct	s_nbr_2
{
  t_nbr		*quot;
  t_nbr		*rest;
}		t_nbr_2;

typedef struct	s_mul
{
  char		*nbr;
  int		nbr_len;
}		t_mul;

t_nbr		*not(t_nbr *n);
t_nbr		*alloc_nbr(t_base *base);
void		free_nbr(t_nbr *nbr);
t_nbr		*add_sub(t_nbr *n1, t_nbr *n2);
t_nbr		*add(t_nbr *n1, t_nbr *n2);
t_nbr		*sub(t_nbr *n1, t_nbr *n2);
t_nbr		*mul_temp(t_mul *nb1, t_mul *nb2, t_base *base);
t_nbr		*mul(t_nbr *n1, t_nbr *n2);
t_nbr		*my_div(t_nbr *n1, t_nbr *n2);
t_nbr_2		*div_ent(t_nbr *n1, t_nbr *n2);
int		bas(char c, t_base *base);
void		my_putchar(char c);
void		my_putstr(const char *str);
int		my_strlen(const char *str);
int		nbr_cmp(t_nbr *n1, t_nbr *n2, int frac);
void		m_denom(t_nbr *n1, t_nbr *n2);
t_nbr		*check_zero(t_nbr *n, int frac);
t_nbr		*read_nbr(char **expr, t_bistro *bistro);
int		is_op(char c, t_bistro *bistro);
int		is_op_infix(char c, t_bistro *bistro);
int		nbr_len(char *expr, int maxsize, t_bistro *bistro);
t_nbr		*read_nbr(char **expr, t_bistro *bistro);
t_nbr		*read_expr_rpn(char *expr, t_bistro *bistro);
t_nbr		*read_expr_infix(char *expr, t_bistro *bistro);
t_bistro	*read_input(void);
void		my_putnstr(char *str, int n);
void		output_nbr(t_nbr *nbr, t_bistro *bistro);
void		output_nbr_infix(t_nbr *nbr, t_bistro *bistro);
void		error_msg(char *msg, int exitcode);
t_nbr		*reduc(t_nbr *n);
t_nbr		*make_calcul_free(t_nbr *nbr1,
				  t_nbr *nbr2,
				  char op,
				  t_bistro *bistro);
void		my_strncpy(char *dest, char *str, int len);
void		my_puterror(char *str);

#endif /* !BISTRO_H */
