PARSINGPATH	:= $(DIRSRC)/parsing

PARSING	:=\
	parse_ants.c

OBJ	:=	$(OBJ) $(PARSING:.c=.o)

$(DIROBJ)/%.o: $(PARSINGPATH)/%.c $(INC)
	$(COMPIL)
