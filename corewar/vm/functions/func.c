/*
** func.c for corewar in /u/a1/legros_b/cvs/corewar/vm
**
** Made by bruno legros
** Login   <legros_b@epita.fr>
**
** Started on  Fri Dec 20 17:37:59 2002 bruno legros
** Last update Fri Dec 20 19:34:18 2002 bruno legros
*/

#include "func.h"

void		inc_qrt(unsigned char r[2], unsigned int nb)
{
  unsigned char	tmp;
  unsigned int	i;

  for (i = 3; 3 - i <= nb; i--)
    {
      tmp = r[i / 2];
      if (!(i % 2))
	tmp >>= 4;
      tmp++;
      r[i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      if (tmp & 0x0f)
	{
	  if (!(i % 2))
	    tmp <<= 4;
	  r[i / 2] |= tmp & ((i % 2) ? 0x0f : 0xf0);
	  break ;
	}
    }
}

void		dec_qrt(unsigned char r[2], unsigned int nb)
{
  unsigned char	tmp;
  unsigned int	i;

  for (i = 3; 3 - i <= nb; i--)
    {
      tmp = r[i / 2];
      if (!(i % 2))
	tmp >>= 4;
      tmp--;
      if ((tmp & 0x0f) != 0x0f)
	{
	  r[i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
	  if (!(i % 2))
	    tmp <<= 4;
	  r[i / 2] |= tmp & ((i % 2) ? 0x0f : 0xf0);
	  break ;
	}
      r[i / 2] |= ((i % 2) ? 0x0f : 0xf0);
    }
}

void		decal_left(unsigned char r[2], char p, unsigned int n)
{
  int		i;
  unsigned char	tmp;
  long int	dec;

  dec = 0;
  for (i = 3 - p; i < 4; i++)
    {
      tmp = r[i / 2];
      if (!(i % 2))
	tmp >>= 4;
      dec <<= 4;
      dec |= tmp & 0x0f;
    }
  dec <<= (n > 16) ? 16 : n;
  for (i = 3; 3 - i <= p; i--)
    {
      tmp = dec & 0x0f;
      dec >>= 4;
      if (!(i % 2))
	tmp <<= 4;
      r[i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      r[i / 2] |= tmp & ((i % 2) ? 0x0f : 0xf0);
    }
}

void		decal_right(unsigned char r[2], char p, unsigned int n)
{
  int		i;
  unsigned char	tmp;
  long int	dec;

  dec = 0;
  for (i = 3 - p; i < 4; i++)
    {
      tmp = r[i / 2];
      if (!(i % 2))
	tmp >>= 4;
      dec <<= 4;
      dec |= tmp & 0x0f;
    }
  dec >>= (n > 16) ? 16 : n;
  for (i = 3; 3 - i <= p; i--)
    {
      tmp = dec & 0x0f;
      dec >>= 4;
      if (!(i % 2))
	tmp <<= 4;
      r[i / 2] &= ((i % 2) ? 0xf0 : 0x0f);
      r[i / 2] |= tmp & ((i % 2) ? 0x0f : 0xf0);
    }
}
