PARSINGPATH	:= $(DIRSRC)/parsing

PARSING	:=\
	parse_anthill.c \
	parse_ants.c \
	parse_command.c \
	parse_comment.c \
	parse_link.c \
	parse_name.c \
	parse_num.c \
	parse_room.c \
	parse_spaces.c \
	step_ants.c \
	step_link.c \
	step_room.c

OBJ	:=	$(OBJ) $(PARSING:.c=.o)

$(DIROBJ)/%.o: $(PARSINGPATH)/%.c $(INC)
	$(COMPIL)
