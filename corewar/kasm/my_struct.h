/*
** my_struct.h for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec 11 11:53:45 2002 olivier lecornet
** Last update Sat Dec 21 18:24:33 2002 nicolas vigier
*/

#ifndef MY_STRUCT_H
# define MY_STRUCT_H

# include "asm.h"

typedef struct		s_word
{
  char			*word;
  char			*codage;
  char			size;
  int			line;
  struct s_word		*next;
}			t_word;

typedef struct		s_label
{
  t_word	       	*word;
  int			addr;
  int			used;
  int			type;
  struct s_label	*next;
}			t_label;

typedef struct		s_error
{
  int			type;
  char			*msg;
  int			line;
  struct s_error	*next;
}			t_error;

typedef struct		s_cmd_list
{
  t_word	       	*cmd[4];
  int			size;
  struct s_cmd_list   	*next;
  int			number;
  void			*cmd_info;
  int			pure_code;
}			t_cmd_list;

typedef	struct	s_info
{
  t_label	*tete_label;
  t_error	*tete_error;
  t_cmd_list   	*tete_cmd;
  t_word	*tete_words;
  char		*name;
  char		*comment;
  int		fd_input;
  int		fd_output;
  char		*inputfile;
  int		size_prog;
  int		size_buf;
  int		pos_buf;
  char		str_buf[MY_BUF_SIZE];
  int		line;
  int		flags;
  int		do_encode;
}		t_info;

typedef struct		s_cmd
{
  char			*cmd;
  char			*codage_cmd;
  int			(* func_ncod_arg1) (t_info *, t_cmd_list *newcmd, t_word *argcmd, int size);
  int			(* func_ncod_arg2) (t_info *, t_cmd_list *newcmd, t_word *argcmd, int size);
  int			nb_quartets_arg1;
  int			nb_quartets_arg2;
  int			size_cmd;
}			t_cmd;

typedef struct	s_directive
{
  char		*name;
  int		size;
  void		(* func) (t_info *all, t_word **word);
}		t_directive;

#endif /* MY_STRUCT_H */
