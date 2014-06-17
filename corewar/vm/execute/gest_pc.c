/*
** gest_pc.c for corewar in /u/a1/august_e/corewar/vm/execute
**
** Made by eric augustin
** Login   <august_e@epita.fr>
**
** Started on  Sun Dec 22 15:48:17 2002 eric augustin
** Last update Sun Dec 22 15:48:18 2002 eric augustin
*/
int	pc2int(unsigned char pc[2])
{
  int	res;

  res = 0;
  res = 256 * pc[0] + pc[1];
  return res;
}

void	dec_pc(unsigned char pc[2])
{
  if ((pc[1] -= 1) == 0xff)
    pc[0] -= 1;
}

void	inc_pc(unsigned char pc[2])
{
  if ((pc[1] += 1) == 0)
    pc[0] += 1;
}
