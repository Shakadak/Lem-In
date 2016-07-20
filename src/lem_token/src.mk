TOK		:=	lem_start.c \
			lem_room.c \
			lem_link.c \
			lem_error.c \
			lem_end.c \
			lem_comment.c \
			lem_ant.c

OBJ		:= $(OBJ) $(TOK:.c=.o)

$(DIROBJ)/%.o: $(DIRTOK)/%.c $(INC)
	$(COMPIL)
