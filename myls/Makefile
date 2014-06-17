##
## Makefile for mysh in /u/a1/vigier_n/c/rendu/mp/myls
##
## Made by nicolas vigier
## Login   <vigier_n@epita.fr>
##
## Started on  Sun Oct 20 17:21:11 2002 nicolas vigier
## Last update Wed Oct 23 07:03:15 2002 nicolas vigier
##

# include architecture-dependent flags
include Makefile-rules.make

INCL	= myls.h
SRC	= compare_func.c list.c makelist.c utils.c \
	  getopt.c main.c print.c my_strcmp.c utils2.c \
          my_putstr.c my_putnbr.c
OBJ	= $(SRC:.c=.o)
CFLAGS	=
NAME	= myls

all: $(OBJ) $(INCL)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~ \#*

distclean: clean
	rm -f $(NAME)
