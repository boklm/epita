##
## Makefile for minishell in /u/a1/vigier_n/c/rendu/mp/minishell
##
## Made by nicolas vigier
## Login   <vigier_n@epita.fr>
##
## Started on  Wed Nov 20 02:26:54 2002 nicolas vigier
## Last update Wed Nov 20 06:12:01 2002 nicolas vigier
##

include Makefile-rules.make

CC	= gcc
SRC	= do_or.c      lst.c        my_putstr.c  my_strndup.c \
	  do_pipe.c    main.c       my_strlen.c  pars.c \
	  builtins.c   error.c      mmalloc.c    my_strncmp.c prompt.c \
	  do_and.c     exec_prg.c   my_putchar.c my_strncpy.c readln.c
OBJ	= $(SRC:.c=.o)
NAME	= minishell

all:echo.so cd.so exit.so $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS)

.c.o:
	$(CC) -c -Wall -W -ansi $<

echo.so: bt_echo.c
	$(CC) -Wall -W -ansi -shared -DPIC -fPIC -o echo.so bt_echo.c

cd.so: bt_cd.c
	$(CC) -Wall -W -ansi -shared -DPIC -fPIC -o cd.so bt_cd.c

exit.so: bt_exit.c
	$(CC) -Wall -W -ansi -shared -DPIC -fPIC -o exit.so bt_exit.c

clean:
	rm -f *.o
	rm -f *~

distclean: clean
	rm -f *.so
	rm -f $(NAME)
