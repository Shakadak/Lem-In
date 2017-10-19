GRAPHPATH	:= $(DIRSRC)/graph

GRAPH	:=\
	init_graph.c

OBJ	:=	$(OBJ) $(GRAPH:.c=.o)

$(DIROBJ)/%.o: $(GRAPHPATH)/%.c $(INC)
	$(COMPIL)
