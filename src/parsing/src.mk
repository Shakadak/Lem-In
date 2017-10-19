PARSINGPATH	:= $(DIRSRC)/parsing

PARSING	:=\
	parse_ants.c \
	parse_command.c \
	parse_comment.c

OBJ	:=	$(OBJ) $(PARSING:.c=.o)

$(DIROBJ)/%.o: $(PARSINGPATH)/%.c $(INC)
	$(COMPIL)
