/*
** aff_errors.c for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Wed Dec 11 13:02:22 2002 olivier lecornet
** Last update Sun Dec 22 13:16:15 2002 nicolas vigier
*/

#include "gest_errors.h"

t_aff_error	tab_err[NB_TYPE_ERROR] =
  {{WAR_MULT_DIRECTIVE, aff_one_error, WARN, MED_DEFAULT, TEXT_MULT_DIR},
   {ERR_FORMAT_ARG, aff_one_error, ERR, TEXT_FORM_ARG, SUF_DEFAULT},
   {ERR_INCONNU_DIR, aff_one_error, ERR, MED_DEFAULT, TEXT_INCON_DIR},
   {ERR_ARG_LONG, aff_one_error, WARN, MED_DEFAULT, TEXT_TRUNC_DIR},
   {ERR_MISS_ARG_DIR, aff_one_error, ERR, MED_DEFAULT, TEXT_MISS_ARG},
   {ERR_BAD_NAME_LABEL, aff_one_error, ERR, MED_DEFAULT, TEXT_LABEL},
   {ERR_MULT_LABEL_DEF, aff_one_error, ERR, MED_DEFAULT, TEXT_MULT_LAB},
   {AFF_MESS, warn_miss_dir, NULL, NULL, NULL},
   {AFF_MESS, warn_miss_dir, NULL, NULL, NULL},
   {ERR_CMD_UNDEFINE, aff_one_error, ERR, MED_DEFAULT, TEXT_UNKNOW},
   {ERR_LABEL_UNDEFINE, aff_one_error, ERR, MED_DEFAULT, TEXT_UNKNOW},
   {ERR_BADFORMAT_ARG, aff_one_error, ERR, MED_DEFAULT, TEXT_BADFORMAT_ARG},
   {ERR_NAME_REGISTER, aff_one_error, ERR, MED_DEFAULT, TEXT_NAME_REGISTER},
   {ERR_EXPR_CSNT, aff_one_error, ERR, MED_DEFAULT, TEXT_EXPR_CSNT},
   {ERR_UNKNOWN_LABEL, aff_one_error, ERR, MED_DEFAULT, TEXT_UNKNOWN_LABEL},
   {WARN_CONST_OVERFLOW, aff_one_error, WARN, MED_DEFAULT, TEXT_CONST_OVERFLOW},
   {ERR_FEW_ARGUMENT, aff_one_error, ERR, MED_DEFAULT, TEXT_FEW_ARGUMENT},
   {ERR_AMBIGOUS_LABEL, aff_one_error, ERR, MED_DEFAULT, TEXT_AMB_LABEL},
   {ERR_CSTE_DIV_0, aff_one_error, ERR, MED_DEFAULT, TEXT_CSTE_DIV_0},
   {WARN_UNUSED_LABEL, aff_one_error, WARN, MED_DEFAULT, TEXT_UNUSED_LABEL}};

void   	aff_stat(int nb_error, int nb_warn)
{
  char 	*tmp;

  my_write(STDOUT_FILENO, "\n", 1);
  if (nb_error)
    {
      my_write(STDOUT_FILENO, "===> ", my_strlen("===> "));
      tmp = my_itoa_base(nb_error, "0123456789", 10);
      my_write(STDOUT_FILENO, "Nbr errors = ", my_strlen("Nbr errors = "));
      my_write(STDOUT_FILENO, tmp, my_strlen(tmp));
      my_write(STDOUT_FILENO, "\n", 1);
    }
  if (nb_warn)
    {
      my_write(STDOUT_FILENO, "===> ", my_strlen("===> "));
      tmp = my_itoa_base(nb_warn, "0123456789", 10);
      my_write(STDOUT_FILENO, "Nbr warnings = ", my_strlen("Nbr warnings = "));
      my_write(STDOUT_FILENO, tmp, my_strlen(tmp));
      my_write(STDOUT_FILENO, "\n", 1);
    }
}

void		aff_errors(t_error *tete)
{
  t_error	*p;
  int		i, nb_error, nb_warn;

  nb_error = 0;
  nb_warn = 0;
  for (p = tete; p; p = p->next)
    {
      for (i = 0; (i < NB_TYPE_ERROR) && (p->type != tab_err[i].type); i++) ;
      if (i < 300)
	tab_err[i].aff_err(p, tab_err[i].pref,
			   tab_err[i].med, tab_err[i].suf);
      else
	my_putstr("t'oublie une erreur tebe de programmeur.\n");
      if ((p->type != AFF_MESS) &&
	  (p->type != ERR_ARG_LONG) &&
	  (p->type != WAR_MULT_DIRECTIVE) &&
	  (p->type != WARN_CONST_OVERFLOW) &&
	  (p->type != WARN_UNUSED_LABEL))
	nb_error++;
      else
	nb_warn++;
    }
  aff_stat(nb_error, nb_warn);
}
