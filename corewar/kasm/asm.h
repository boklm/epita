/*
** asm.h for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Tue Dec  3 17:24:46 2002 olivier lecornet
** Last update Thu Dec 19 23:21:46 2002 nicolas vigier
*/

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "../data.h"
# include "macro.h"
# include "my_struct.h"
# include "uses_str/uses_str.h"
# include "uses_nbr/uses_nbr.h"
# include "uses_parse/uses_parse.h"
# include "gest_arg/gest_arg.h"
# include "gest_error/gest_errors.h"
# include "gest_encode/gest_encode.h"
# include "gest_cmd/gest_cmd.h"
# include "verif_syntaxe.h"
# include "create_list_word.h"
# include "gest_directives.h"
# include "gest_pure_code.h"
# include "gest_label.h"
# include "existing_label.h"
# include "gest_unknown_cmd.h"
# include "check_errors.h"
# include "concat_expr.h"
# include "output_core/output_core.h"

extern t_cmd		cmds[NB_CMDS];
extern t_directive    	tab_direc[NB_DIRECTIVES];

#endif /* ASM_H */
