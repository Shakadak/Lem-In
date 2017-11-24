MAINPATH	:= $(DIRSRC)/main

MAIN	:=\
	get_anthill.c \
	get_lightest_neighbor.c \
	main.c \
	transfer_ants.c \
	utils.c \

OBJ	:=	$(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(MAINPATH)/%.c $(INC)
	$(COMPIL)
