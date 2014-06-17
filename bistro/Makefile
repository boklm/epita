##
## Makefile<2> for bistromathique in /u/a1/legros_b/c/rendu/mp/myls/list
##
## Made by bruno legros
## Login   <legros_b@epita.fr>
##
## Started on  Thu Oct 17 14:04:29 2002 bruno legros
## Last update Sat Nov  9 22:53:18 2002 bruno legros
##

include Makefile-rules.make

CFLAGS = $(WARN) $(OPTI)

NAME = bistromathique

SRC = add_sub.c common.c input.c mul.c output.c utils2.c \
alloc.c div.c main.c my_put.c read_expr.c utils.c reduc.c\
read_expr_infix.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(LDDEBUG) $(DEF) -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDDEBUG) $(DEF)

clean:
	$(RM) *~ \#* *.o

distclean: clean
	$(RM) $(NAME)

re: distclean all
	echo done
