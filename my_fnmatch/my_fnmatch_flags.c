/*
** my_fnmatch_flags.c for piscine in /u/a1/vigier_n/c/rendu/piscine/j10
** 
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
** 
** Started on  Wed Oct  2 15:03:06 2002 nicolas vigier
** Last update Sat Oct  5 20:40:18 2002 nicolas vigier
*/

#include "my_fnmatch_flags.h"

int	comp_interv(const char *pattern, const char *string, int flags)
{
  if (*pattern++ == *string)
    return 1;
  while (*pattern != ']')
    {
      if (*pattern == '-' && (flags & MY_FNM_HANDLE_RANGES) &&
	  (*(pattern + 1) != ']'))
	{
	  if (*string > *(pattern - 1) && *string < *(pattern + 1))
	    return 1;
	  else
	    pattern++;
	}
      if (*pattern == *string)
	return 1;
      pattern++;
    }
  return 0;
}

unsigned int	comp_char(const char *pattern, const char *string, int flags)
{
  unsigned int	size;

  if (*pattern != '[' || !(flags & MY_FNM_HANDLE_CLASSES))
    return (*pattern == *string);
  size = 2;
  while (pattern[size] != ']')
    size++;
  size++;
  if (pattern[1] == '!' && (flags & MY_FNM_HANDLE_COMPLEMENTS))
    {
      if (pattern[2] == ']' && size == 3)
	while (pattern[size++] != ']')
	  ;
      return size * !comp_interv(pattern + 2, string, flags);
    }
  else
    return size * comp_interv(pattern + 1, string, flags);
}

int		my_fnmatch_rec(const char *pattern, const char *string,
		   int flags)
{
  unsigned int	c;

  if (!*pattern)
    return 1;
  if (!*string)
    {
      if (*pattern == '*')
	return my_fnmatch_rec(pattern + 1, string, flags);
      else
	return 0;
    }
  if (*pattern == '*')
    return my_fnmatch_rec(pattern, string + 1, flags) +
      my_fnmatch_rec(pattern + 1, string, flags);
  if (*pattern == '?' && (flags & MY_FNM_HANDLE_QMARK))
    return my_fnmatch_rec(pattern + 1, string + 1, flags);
  if ((c = comp_char(pattern, string, flags)))
      return my_fnmatch_rec(pattern + c, string + 1, flags);
  else
    return 0;
}

int	my_fnmatch(const char *pattern, const char *string,
		   int flags)
{
  int	nb_res;

  if (!pattern || !string)
    return 0;
  nb_res = 0;
  do
    nb_res += my_fnmatch_rec(pattern, string, flags);
  while (*string++);
  return nb_res;
}
