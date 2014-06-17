##
## Makefile for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
## 
## Made by olivier lecornet
## Login   <lecorn_o@epita.fr>
## 
## Started on  Tue Dec  3 17:20:14 2002 olivier lecornet
## Last update Wed Dec 11 14:52:39 2002 olivier lecornet
##

# include architecture-dependent flags
include ../Makefile-rules.make

RM       = rm -f
TARGET 	 = gest_error
DEBUG    = -g
CFLAGS   = $(WARN)
AR	 = ar rc
RANLIB	 = ranlib

SRC =   gest_errors.c \
	aff_errors.c \
	aff_one_err.c \
	warn_miss_dir.c

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

