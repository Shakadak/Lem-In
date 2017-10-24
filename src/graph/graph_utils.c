#include "structs.h"
#include "lemin.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	print_graph(t_room *rooms, int rnb)
{
	int		i;
	t_lst	*co;

	i = 0;
	while (i < rnb)
	{
		printf("room:'%s' have weight:'%i' and this connections is:\n",
				rooms[i].name, rooms[i].weight);
		co = rooms[i].conn;
		while (co != NULL)
		{
			printf("> %s-%s\n", rooms[i].name,
					(char *)((t_room *)co->content)->name);
			co = co->next;
		}
		i++;
	}
}
