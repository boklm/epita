##
## Makefile for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
##
## Made by olivier lecornet
## Login   <lecorn_o@epita.fr>
##
## Started on  Tue Dec  3 17:20:14 2002 olivier lecornet
## Last update Fri Dec 20 01:39:56 2002 nicolas vigier
##

# include architecture-dependent flags
include ../Makefile-rules.make

RM       = rm -f
TARGET 	 = gest_cmd.a
DEBUG    = -g
CFLAGS   = $(WARN)
AR	 = ar rc
RANLIB	 = ranlib

SRC =   gest_cmd.c \
	add_cmdlist.c \
	init_cmdlist.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $(TARGET) $(OBJ)
	$(RANLIB) $(TARGET)
	(mv $(TARGET) ../)

clean:
	$(RM) *~ \#* *.o

distclean: clean
	$(RM) $(TARGET).a

re: distclean all

