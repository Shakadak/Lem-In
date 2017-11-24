GRAPHPATH	:= $(DIRSRC)/graph

GRAPH	:=\
	check_rooms.c\
	find_type.c\
	init_graph.c\
	graph_utils.c\
	weight_from_end.c

OBJ	:=	$(OBJ) $(GRAPH:.c=.o)

$(DIROBJ)/%.o: $(GRAPHPATH)/%.c $(INC)
	$(COMPIL)
