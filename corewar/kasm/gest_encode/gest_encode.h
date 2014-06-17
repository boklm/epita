/*
** gest_encode.h for corewar in /u/a1/vigier_n/asm_new
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Dec 18 04:07:50 2002 nicolas vigier
** Last update Sat Dec 21 12:05:30 2002 nicolas vigier
*/

#ifndef GEST_ENCODE_H
# define GEST_ENCODE_H

int		gest_encode(t_info *all);

int		recup_constante(t_info *info, t_cmd_list *cmdlist,
				t_word *word, int size);

int		recup_register(t_info *info, t_cmd_list *cmdlist,
			       t_word *word, int size);

int		recup_register_add(t_info *info, t_cmd_list *cmdlist,
				   t_word *word, int size);

char		invert_quartet(char elt);

int		recup_pure_code(t_info *info, t_cmd_list *cmdlist);

#endif /* GEST_ENCODE_H */
