MAINPATH	:= $(DIRSRC)/main

MAIN	:=\
	get_anthill.c \
	main.c

OBJ	:=	$(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(MAINPATH)/%.c $(INC)
	$(COMPIL)
