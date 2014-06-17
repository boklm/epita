##
## Makefile for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm/gest_arg
##
## Made by olivier lecornet
## Login   <lecorn_o@epita.fr>
##
## Started on  Tue Dec  3 17:20:14 2002 olivier lecornet
## Last update Sun Dec 22 11:58:53 2002 nicolas vigier
##

# include architecture-dependent flags
include ../Makefile-rules.make

RM       = rm -f
TARGET 	 = gest_arg.a
DEBUG    = -g
CFLAGS   = $(WARN)
AR	 = ar rc
RANLIB	 = ranlib

SRC =   gest_arg.c \
	arg_nc.c \
	arg_help.c \
	arg_verbose.c \
	arg_version.c

DEPEND = gest_arg.h

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ) $(DEPEND)
	$(AR) $(TARGET) $(OBJ)
	$(RANLIB) $(TARGET)
	(mv $(TARGET) ../)

clean:
	$(RM) *~ \#* *.o

distclean: clean
	$(RM) $(OBJ)

re: distclean all

