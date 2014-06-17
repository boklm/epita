##
## Makefile for  in /u/a1/lecorn_o/corewar_asm/corewar_asm
##
## Made by olivier lecornet
## Login   <lecorn_o@epita.fr>
##
## Started on  Thu Dec 12 16:34:03 2002 olivier lecornet
## Last update Sat Dec 21 11:23:14 2002 nicolas vigier
##

# include architecture-dependent flags
include Makefile-rules.make

RM       = rm -f
TARGET 	 = asm
DEBUG    = -g
CFLAGS   = $(WARN)

SRC =   main.c \
	verif_syntaxe.c \
	gest_directives.c \
	gest_pure_code.c \
	gest_label.c \
	gest_unknown_cmd.c \
	create_list_word.c \
	take_name.c \
	take_comment.c \
	existing_label.c \
	check_errors.c \
	concat_expr.c

LIB	= uses_parse.a gest_arg.a output_core.a gest_error.a \
	  gest_cmd.a gest_encode.a uses_str.a

DEPEND = asm.h

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): configure $(OBJ) $(DEPEND) lib
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIB)

configure:
	(./configure)

lib:
	(cd uses_str; make)
	(cd uses_parse; make)
	(cd gest_arg; make)
	(cd gest_error; make)
	(cd gest_cmd; make)
	(cd gest_encode; make)
	(cd output_core; make)

clean:
	rm -rf *.o *~ \#* *.a
	(cd uses_str; make clean)
	(cd uses_parse; make clean)
	(cd gest_arg; make clean)
	(cd gest_error; make clean)
	(cd gest_cmd; make clean)
	(cd gest_encode; make clean)
	(cd output_core; make clean)

distclean: clean
	$(RM) $(TARGET)
	(cd uses_str; make distclean)
	(cd uses_parse; make distclean)
	(cd gest_arg; make distclean)
	(cd gest_error; make distclean)
	(cd gest_cmd; make distclean)
	(cd gest_encode; make distclean)
	(cd output_core; make distclean)

re: distclean all
