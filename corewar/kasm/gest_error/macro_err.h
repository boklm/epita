/*
** macro_err.h for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec 11 12:30:48 2002 olivier lecornet
** Last update Sun Dec 22 11:19:59 2002 nicolas vigier
*/

#ifndef MACRO_ERR_H
# define MACRO_ERR_H

# define NB_TYPE_ERROR	20

/* ERREUR DE LABEL */
# define ERR_LABEL_UNDEFINE	1
# define ERR_BAD_NAME_LABEL	2
# define ERR_MULT_LABEL_DEF	3
# define ERR_AMBIGOUS_LABEL	4
# define WARN_UNUSED_LABEL	5

/* ERREUR DE COMMANDES */
# define ERR_CMD_UNDEFINE	101
# define ERR_FEW_ARGUMENT	102
# define ERR_MANY_ARGUMENT	103
# define ERR_EXPR_CSNT		104
# define ERR_NAME_REGISTER     	105
# define ERR_BADFORMAT_ARG	106
# define ERR_UNKNOWN_LABEL	107
# define ERR_CSTE_DIV_0		108
# define WARN_CONST_OVERFLOW	109

/* ERREUR DE DIRECTIVES */
# define WAR_MULT_DIRECTIVE	201
# define ERR_FORMAT_ARG		202
# define ERR_INCONNU_DIR	203
# define ERR_ARG_LONG		204
# define ERR_MISS_ARG_DIR	205

# define AFF_MESS	    	300

# define TEXT_MISSING_NAME	"Warning \t: Missing Champion's Name.\n"
# define TEXT_MISSING_COMMENT	"Warning \t: Missing Champion's Comment.\n"

/* TEXT en tete */
# define WARN	"Warning \t: Line "
# define ERR	"Syntax Error \t: Line "

/* TEXT de milieu */
# define MED_DEFAULT	" : "
# define TEXT_FORM_ARG	" : Invalid format argument for "

/* TEXT de fin */
# define SUF_DEFAULT		"\n"
# define TEXT_MISS_ARG		" : Missing Argument.\n"
# define TEXT_MULT_LAB		" : Multiple label definition.\n"
# define TEXT_MULT_DIR		" : Multiple directive definition.\n"
# define TEXT_INCON_DIR		" : Unknown Directive.\n"
# define TEXT_TRUNC_DIR		"'s argument is truncated.\n"
# define TEXT_BADFORMAT_ARG	" : Bad format argument.\n"
# define TEXT_NAME_REGISTER	" : Register expected.\n"
# define TEXT_EXPR_CSNT		" : Bad constant expression.\n"
# define TEXT_UNKNOWN_LABEL	" : Unknown label.\n"
# define TEXT_CONST_OVERFLOW	" : Constant out of range. Truncated.\n"
# define TEXT_FEW_ARGUMENT	" : Missing argument.\n"
# define TEXT_AMB_LABEL		" : Ambigous label definition.\n"
# define TEXT_CSTE_DIV_0	" : Division by 0 in constante.\n"
# define TEXT_UNUSED_LABEL	" : Unused label.\n"

# define TEXT_LABEL	" : Invalid format for a label.\n"
# define TEXT_UNKNOW	" : Unknown Identifier.\n"

#endif /* MACRO_ERR_H */
