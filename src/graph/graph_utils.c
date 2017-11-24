#include "inc/structs.h"
#include "inc/lemin.h"
#include "libft/inc/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	print_graph(t_room const *rooms, size_t rnb)
{
	size_t	i;
	size_t	co;
	t_room	**connections;

	i = 0;
	while (i < rnb)
	{
		printf("room:'%s' has weight:'%i' and its connections are:\n",
				rooms[i].name, rooms[i].weight);
		co = 0;
		connections = (t_room **)rooms[i].conn.head;
		while (co < rooms[i].conn.used)
		{
			printf("> %s-%s\n", rooms[i].name, connections[co]->name);
			co += 1;
		}
		i++;
	}
}
