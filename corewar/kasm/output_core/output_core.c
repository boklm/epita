/*
** output_core.c for corewar in /u/a1/vigier_n/corewar/asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Thu Dec 19 22:58:59 2002 nicolas vigier
** Last update Sun Dec 22 13:18:55 2002 nicolas vigier
*/

#include "../asm.h"

static void	output_str(t_outputfile *output, char *str, int size)
{
  int		i;

  i = 0;
  while (str[i] && i < size)
    {
      output_char(output, str[i] / 16);
      output_char(output, str[i]);
      i++;
    }
  while (i++ < size)
    {
      output_char(output, 0);
      output_char(output, 0);
    }
}

static void    	output_num_32(t_outputfile *output, int num)
{
  int		i;

  for (i = 0; i < 4; i++)
    {
      output_char(output, num / 16);
      output_char(output, num);
      num /= 256;
    }
}

static char	*output_file(char *inputfile)
{
  int		size;
  char		*res;

  if ((size = my_strlen(inputfile)) > 1 && inputfile[size - 1] == 's' &&
      inputfile[size - 2] == '.')
    {
      res = xmalloc(size + 3);
      res = my_strcpy(res, inputfile);
      res[size - 1] = 0;
      res = my_strcat(res, "cor");
    }
  else
    {
      res = malloc(size + 5);
      res = my_strcpy(res, inputfile);
      res = my_strcat(res, ".cor");
    }
  my_putstrstr("Output file: ^\n", res);
  return res;
}

int		output_core(t_info *info)
{
  t_outputfile	*output;
  char		*outputfile;
  t_word	*word;
  int		i;
  int		j;
  t_cmd_list	*cmdlist;

  output = output_init();
  cmdlist = info->tete_cmd;

  output_num_32(output, COREWAR_EXEC_MAGIC);
  output_num_32(output, info->size_prog);
  output_str(output, info->name, PROG_NAME_LENGTH);
  output_str(output, info->comment, PROG_COMMENT_LENGTH);
  while (cmdlist)
    {
      for (j = 0; (word = cmdlist->cmd[j]); j++)
	for (i = 0; i < word->size; i++)
	  output_char(output, invert_quartet(word->codage[i]));
      cmdlist = cmdlist->next;
    }
  outputfile = output_file(info->inputfile);
  output_write(output, outputfile);
  return 1;
}
