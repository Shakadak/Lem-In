MAINPATH	:= $(DIRSRC)/main

MAIN	:=\
	main.c

OBJ	:=	$(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(MAINPATH)/%.c $(INC)
	$(COMPIL)
