GRAPHPATH	:= $(DIRSRC)/graph

GRAPH	:=\
	init_graph.c\
	graph_utils.c

OBJ	:=	$(OBJ) $(GRAPH:.c=.o)

$(DIROBJ)/%.o: $(GRAPHPATH)/%.c $(INC)
	$(COMPIL)
