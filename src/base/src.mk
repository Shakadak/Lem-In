BASE	:=	put_weight.c \
			main.c \
			get_token.c \
			get_room.c \
			get_map.c \
			get.c \
			display_ants.c \
			check_line.c

OBJ			:=	$(OBJ) $(BASE:.c=.o)

$(DIROBJ)/%.o: $(DIRBASE)/%.c $(INC)
	$(COMPIL)
