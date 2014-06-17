#include "utils.h"

/*
** In the registers variables are stored in big endian
** It is important for the lsl command for example
*/
void	num2reg(unsigned int num, unsigned char reg[2])
{
  int	i;

  for (i = 1; i >= 0; i--)
    {
      reg[i] = num % 256;
      num /= 256;
    }
}

int		reg2int(unsigned char reg[2])
{
  int		res;
  int		neg;
  unsigned char	tmp[2];

  tmp[0] = reg[0];
  tmp[1] = reg[1];
  neg = 0;
  if (tmp[0] & 0x80)
    {
      neg = 1;
      tmp[0] = ~tmp[0];
      tmp[1] = ~tmp[1];
      tmp[1]++;
      if (!tmp[1])
	tmp[0]++;
    }
  res = tmp[1] + (256 * tmp[0]);
  return (neg ? -res : res);
}

void	int2reg(unsigned char reg[2], int n)
{
  int	neg;

  neg = 0;
  if (n < 0)
    {
      neg = 1;
      n = -n;
    }
  reg[1] = n % 256;
  reg[0] = n / 256;
  if (neg)
    {
      reg[0] = ~reg[0];
      reg[1] = ~reg[1];
      reg[1]++;
      if (!reg[1])
	reg[0]++;
    }
}

/*
** return n % IDX_MOD (n signed)
*/
int		neg_mod(int n, int mod)
{
  if (mod < 0)
    mod = -mod;
  while (n < -mod || n >= mod)
    {
      if (n < 0)
	n += 2 * mod;
      else
	n -= 2 * mod;
    }
  return n;
}

unsigned int	get_code_size(unsigned char buf[4])
{
  int		i;
  int		res;

  res = 0;
  for (i = 0; i < 4; i++)
    {
      res *= 256;
      res += buf[3 - i];
    }
  return res;
}
