##
## Makefile for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
##
## Made by olivier lecornet
## Login   <lecorn_o@epita.fr>
##
## Started on  Tue Dec  3 17:20:14 2002 olivier lecornet
## Last update Thu Dec 19 04:36:04 2002 nicolas vigier
##

# include architecture-dependent flags
include ../Makefile-rules.make

RM       = rm -f
TARGET 	 = uses_parse.a
DEBUG    = -g
CFLAGS   = $(WARN)
AR	 = ar rc
RANLIB	 = ranlib

SRC =   delete_comment.c \
	is_space.c \
	isolate_word.c \
	next_word.c \
	delete_end_spaces.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $(TARGET) $(OBJ)
	$(RANLIB) $(TARGET)
	(mv $(TARGET) ../)

clean:
	$(RM) *~ \#* *.o

distclean: clean
	$(RM) $(TARGET)

re: distclean all

