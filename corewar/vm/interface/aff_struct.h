/*
** aff_struct.h for  in /u/a1/lecorn_o/c/corewar/vm
** 
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
** 
** Started on  Sat Dec 21 17:21:54 2002 olivier lecornet
** Last update Sat Dec 21 17:21:54 2002 olivier lecornet
*/

#ifndef AFF_STRUCT_H
# define AFF_STRUCT_H


typedef struct	s_aff_player
{
  char		*color;
  char		*id;
}		t_aff_player;

typedef struct	s_env
{
  int		line;
  int		col;
  int		nb_player;
  int		scale;
  char		*mem;
}		t_env;


#endif /* AFF_STRUCT_H */
