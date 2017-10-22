PARSINGPATH	:= $(DIRSRC)/parsing

PARSING	:=\
	parse_ants.c \
	parse_command.c \
	parse_comment.c \
	parse_link.c \
	parse_name.c \
	parse_num.c \
	parse_room.c \
	parse_spaces.c

OBJ	:=	$(OBJ) $(PARSING:.c=.o)

$(DIROBJ)/%.o: $(PARSINGPATH)/%.c $(INC)
	$(COMPIL)
