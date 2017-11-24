MAINPATH	:= $(DIRSRC)/main

MAIN	:=\
	get_anthill.c \
	get_lightest_neighbor.c \
	utils.c \
	main.c

OBJ	:=	$(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(MAINPATH)/%.c $(INC)
	$(COMPIL)
