/*
** recup_register.c for corewar in /u/a1/vigier_n/asm_new
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Dec 18 03:51:38 2002 nicolas vigier
** Last update Sun Dec 22 13:41:33 2002 nicolas vigier
*/

#include "../asm.h"
#include "gest_encode.h"

static char	atoi_2(t_info *info, t_word *word, char **str, char endchar)
{
  unsigned char	res;

  res = 0;
  while (**str && **str != endchar)
    {
      if (!my_isdigit(**str))
	{
	  add_error(info->tete_error, word->word, ERR_NAME_REGISTER, word->line);
	  return 0;
	}
      res *= 10;
      res += **str - '0';
      ++*str;
    }
  if (res > 15)
    {
      add_error(info->tete_error, word->word, ERR_NAME_REGISTER, word->line);
      return 0;
    }
  return res;
}

int		recup_register(t_info *info, t_cmd_list *cmdlist,
			       t_word *word, int size)
{
  char		*tmp;
  t_cmd_list	*useless_cmdlist;

  word->size = size;
  useless_cmdlist = cmdlist;
  tmp = word->word;
  if (*tmp++ != 'r' || !(my_isdigit(*tmp)))
    {
      add_error(info->tete_error, word->word, ERR_NAME_REGISTER, word->line);
      return 0;
    }
  word->codage = malloc(1);
  *word->codage = invert_quartet(atoi_2(info, word, &tmp, ','));
  return 1;
}

int		recup_register_add(t_info *info, t_cmd_list *cmdlist, t_word *word, int size)
{
  char		*tmp;
  t_cmd_list	*tmpcmdlist;
  int		len;

  len = my_strlen(word->word);
  tmp = word->word;
  word->size = size;
  tmpcmdlist = cmdlist;
  if ((*tmp++ != '[' || *tmp++ != 'r' || !(my_isdigit(*tmp)) ||
       (word->word[len - 1] != ']'))
      && (word->word[len - 1] != ',' || word->word[len - 2] != ']'))
    {
      info->tete_error = add_error(info->tete_error, word->word, ERR_NAME_REGISTER, word->line);
      return 0;
    }
  word->codage = malloc(size);
  *word->codage = invert_quartet(atoi_2(info, word, &tmp, ']'));
  return 1;
}
