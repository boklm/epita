##
## Makefile<2> for  in /u/a1/lecorn_o/c/corewar/vm
##
## Made by olivier lecornet
## Login   <lecorn_o@epita.fr>
##
## Started on  Sat Dec 21 17:21:10 2002 olivier lecornet
## Last update Sun Dec 22 19:27:56 2002 olivier lecornet
##

include ../Makefile-rules.make

RANL	= ranlib
AR	= ar rc
TARGET	= aff

SRC	= aff_cadre.c \
	  aff_info_player.c \
	  aff_init.c \
	  aff_table.c \
	  aff_uses.c \
	  aff_uses_mem.c \
	  gest_signaux.c \
	  aff_actual_table.c \
	  aff_result.c

OBJ	= $(SRC:.c=.o)

LINFO	= -L/u/dp/public/arch/`uname -m`-`uname -s`/lib
IINFO	= -I/u/dp/public/include -I/u/dp/public/include/ncurses

all: $(OBJ)
	ar rc $(TARGET).a $(OBJ)
	ranlib $(TARGET).a

clean:
	rm -f *.o *~

distclean: clean
	rm -f $(TARGET).a
