/*
** my_strncmp.c for piscine in /u/a1/vigier_n/c/rendu/piscine/j3
** 
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
** 
** Started on  Wed Sep 25 21:06:55 2002 nicolas vigier
** Last update Thu Sep 26 01:14:52 2002 nicolas vigier
*/

int	my_strncmp(const char *s1, const char *s2, int n)
{
  while (n-- && (*s1 == *s2++))
      if (!*s1++)
	return 0;
  if (++n)
    return *s1 - *--s2;
  else
    return 0;
}
