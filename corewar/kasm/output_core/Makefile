##
## Makefile for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
##
## Made by olivier lecornet
## Login   <lecorn_o@epita.fr>
##
## Started on  Tue Dec  3 17:20:14 2002 olivier lecornet
## Last update Thu Dec 19 23:01:02 2002 nicolas vigier
##

# include architecture-dependent flags
include ../Makefile-rules.make

RM       = rm -f
TARGET 	 = output_core
DEBUG    = -g
CFLAGS   = $(WARN)
AR	 = ar rc
RANLIB	 = ranlib

SRC =   output_core.c \
	output_char.c \
	output_init.c \
	output_write.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $(TARGET).a $(OBJ)
	$(RANLIB) $(TARGET).a
	(mv $(TARGET).a ../)

clean:
	$(RM) *~ \#* *.o

distclean: clean
	$(RM) $(TARGET).a

re: distclean all

