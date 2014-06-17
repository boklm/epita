/*
** output_core.h for corewar in /u/a1/vigier_n/corewar/corewar_asm/corewar_asm
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Tue Dec 10 11:54:06 2002 nicolas vigier
** Last update Sat Dec 21 14:57:36 2002 nicolas vigier
*/

#ifndef OUTPUT_CORE_H
# define OUTPUT_CORE_H

# define ALLOC_SIZE	900

struct	s_outputfile
{
  char	*output;
  char	*ptr;
  int	allocated;
  int	quartet_1;
};
typedef struct s_outputfile t_outputfile;

int		output_char(t_outputfile *output, char elt);
t_outputfile	*output_init(void);
int		output_write(t_outputfile *output, char *filename);
int		output_core(t_info *info);
void		aff_elt(char elt);

#endif /* OUTPUT_CORE_H */
