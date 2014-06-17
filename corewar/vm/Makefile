##
## Makefile<2> for bistromathique in /u/a1/legros_b/c/rendu/mp/myls/list
##
## Made by bruno legros
## Login   <legros_b@epita.fr>
##
## Started on  Thu Oct 17 14:04:29 2002 bruno legros
## Last update Sun Dec 22 18:11:47 2002 eric augustin
##

include Makefile-rules.make

CFLAGS = $(WARN) $(OPTI)

NAME = corewar

LIB = $(LIB_)

LINFO	= -L/u/dp/public/arch/`uname -m`-`uname -s`/lib
IINFO	= -I/u/dp/public/include -I/u/dp/public/include/ncurses

SRC = init.c main.c utils.c add_proc_in_vm.c\
error/my_error.c\
gest_arg/gest_arg.c\
common/my_atoi.c common/my_strlen.c common/my_strncmp.c common/my_write.c\
common/my_hexdump.c\
common/my_itoa.c \
common/is_num.c\
gest_proc/gest_proc.c\
functions/func.c\
functions/func1.c\
functions/func2.c\
functions/func3.c\
functions/func4.c\
functions/func5.c\
functions/func6.c\
functions/func7.c\
execute/vm_execute.c \
execute/gest_inst.c \
execute/gest_pc.c \
execute/init_arg.c \
execute/init1.c \
execute/init2.c \
execute/vm_func.c \
execute/vm_func2.c \
execute/trace.c\
execute/trace_func1.c\
execute/trace_func2.c\
execute/check_fork.c\
write/write.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(BONUS) $(LDDEBUG) $(DEF) $(IINFO) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDDEBUG) $(DEF) $(LIB)

bonus: $(OBJ)
	(cd interface;make)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDDEBUG) $(DEF) $(LIB) $(IINFO) $(LINFO) interface/aff.a -lncurses -ggdb

clean:
	$(RM) *~ \#* *.o
	$(RM) error/*~ error/\#* error/*.o
	$(RM) common/*~ common/\#* common/*.o
	$(RM) gest_arg/*~ gest_arg/\#* gest_arg/*.o
	$(RM) gest_proc/*~ gest_proc/\#* gest_proc/*.o
	$(RM) functions/*~ functions/\#* functions/*.o
	$(RM) execute/*~ execute/\#* execute/*.o
	$(RM) write/*~ write/\#* write/*.o
	(cd interface;make clean)

distclean: clean
	$(RM) $(NAME)
	(cd interface;make distclean)

re: distclean all
	echo done
