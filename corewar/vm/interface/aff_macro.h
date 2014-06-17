/*
** aff_macro.h for  in /u/a1/lecorn_o/c/corewar/vm
**
** Made by olivier lecornet
** Login   <lecorn_o@epita.fr>
**
** Started on  Sat Dec 21 17:21:47 2002 olivier lecornet
** Last update Sun Dec 22 13:07:24 2002 olivier lecornet
*/

#ifndef AFF_MACRO_H
# define AFF_MACRO_H

# define MY_NORM	"\033[0;m"
# define MY_BLACK	"\033[0;30m"
# define MY_RED		"\033[0;31m"
# define MY_GREEN	"\033[0;32m"
# define MY_BROWN	"\033[0;33m"
# define MY_BLUE	"\033[0;34m"
# define MY_PURPLE	"\033[0;35m"
# define MY_CYAN	"\033[0;36m"
# define MY_GRIS	"\033[0;37m"
# define MY_GRIS_DARK	"\033[1;30m"
# define MY_RED_CL	"\033[1;31m"
# define MY_GREEN_CL	"\033[1;32m"
# define MY_YELLOW	"\033[1;33m"
# define MY_BLUE_CL	"\033[1;34m"
# define MY_PURPLE_CL	"\033[1;35m"
# define MY_CYAN_CL	"\033[1;36m"
# define MY_WHITE      	"\033[1;37m"


# define BACK_BLACK	"\033[0;40m"
# define BACK_RED       "\033[0;41m"
# define BACK_GREEN	"\033[0;42m"
# define BACK_BROWN	"\033[0;43m"
# define BACK_BLUE	"\033[0;44m"
# define BACK_PURPLE    "\033[0;45m"
# define BACK_CYAN	"\033[0;46m"
# define BACK_GRIS	"\033[0;47m"



# define MY_CLEAR	"\033[H\E[2J"
# define MY_RECUP	"\033[?1047l\E[?1048l"

# define MAX_NB_PLAYER	15

#endif /* AFF_MACRO_H */
