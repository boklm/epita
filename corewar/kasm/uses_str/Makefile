##
## Makefile for  in /u/a1/lecorn_o/c/rendu/proj/corewar/asm
##
## Made by olivier lecornet
## Login   <lecorn_o@epita.fr>
##
## Started on  Tue Dec  3 17:20:14 2002 olivier lecornet
## Last update Sun Dec 22 13:09:25 2002 nicolas vigier
##

# include architecture-dependent flags
include ../Makefile-rules.make

RM       = rm -f
TARGET 	 = uses_str
DEBUG    = -g
CFLAGS   = $(WARN)
AR	 = ar rc
RANLIB	 = ranlib

SRC =   my_strncmp.c \
	my_strcmp.c \
	my_strcasecmp.c \
	my_strlen.c \
	my_strcat.c \
	my_strdup.c \
	my_strcpy.c \
	my_strncpy.c \
	getln.c \
	my_isdigit.c \
	my_isupper.c \
	my_tolower.c \
	my_putchar.c \
	my_putstr.c \
	my_putnbr.c \
	my_putstrstr.c \
	my_putstrnbr.c \
	my_system.c

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
