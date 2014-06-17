##
## Makefile for my_ftpd in .
##
## Made by jean-yves tourtet
## Login   <tourte_j@epita.fr>
##
## Started on  Fri Nov 29 20:41:51 2002 jean-yves tourtet
## Last update Wed Dec  4 07:15:36 2002 nicolas vigier
##

include Makefile-rules.make

NAME1   = my_ftpd
NAME2   = add_user_db
NAME3   = rmv_user_db
RM      = rm -f
SRC1    = cmd.c error.c main_serv.c my_tools.c netutils.c\
          readln.c serv_cl.c strutils.c user_ident.c\
          pass_ident.c utils.c main.c cmd_port.c activ_mode.c help.c \
	  cmd_list.c cmd_stor.c cmd_retr.c encrypt_pass.c \
	  logging.c listc.c cf.c cmd_type.c getopt.c passiv_mode.c \
	  cmd_pasv.c cmd_quit.c cmd_cwd.c cmd_pwd.c cmd_dele.c cmd_mkd.c\
          cmd_rmd.c cmd_setpass.c cmd_setuser.c cmd_unknow.c cmd_help.c \
	  cmd_syst.c
SRC2    = my_tools.c utils.c encrypt_pass.c error.c write_out.c add_user_db.c
SRC3    = my_tools.c error.c write_out.c rmv_users_db.c
OBJ1    = $(SRC1:.c=.o)
OBJ2    = $(SRC2:.c=.o)
OBJ3    = $(SRC3:.c=.o)
INCL1   = cmd.h error.h main_serv.h my_tools.h netutils.h\
          readln.h serv_cl.h strutils.h user_ident.h\
          pass_ident.h utils.h cmd_port.h activ_mode.h help.h \
	  cmd_list.h cmd_stor.h cmd_retr.h encrypt_pass.h \
	  logging.h listc.h cf.h cmd_type.h getopt.h passiv_mode.h \
	  cmd_pasv.h cmd_quit.h cmd_cwd.h cmd_pwd.h cmd_dele.h cmd_mkd.h \
          cmd_rmd.h cmd_setpass.h cmd_setuser.h cmd_unknow.h cmd_help.h \
	  cmd_syst.h
INCL2   = my_tools.h utils.h encrypt_pass.h error.h write_out.h add_user_db.h
INCL3   = my_tools.h error.h write_out.h rmv_users_db.h
IPATH   = -I. -I/usr/pkg/include -I/usr/local/include
LPATH   = -L. -L/usr/pkg/lib -L/usr/local/lib

LIBS	= $(ARCHLIBS)
CFLAGS  = $(WARN) $(OPTI) $(IPATH)
LDFLAGS = $(WARN) $(OPTI) $(LPATH) $(LIBS)

all: $(NAME1) $(NAME2) $(NAME3)

$(NAME1): $(OBJ1) $(INCL1)
	$(CC) $(LDFLAGS) -o $@ $(OBJ1)

$(NAME2): $(OBJ2) $(INCL2)
	$(CC) $(LDFLAGS) -o $@ $(OBJ2)


$(NAME3): $(OBJ3) $(INCL3)
	 $(CC) $(LDFLAGS) -o $@ $(OBJ3)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) \#* *~
	$(RM) $(OBJ1) $(OBJ2) $(OBJ3)

distclean: clean
	$(RM) $(NAME1) $(NAME2) $(NAME3)
	$(RM) Makefile-rules.make
