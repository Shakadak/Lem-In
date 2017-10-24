#include "structs.h"
#include "lem-in.h"
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

void	what_error(unsigned int error)
{
	if (error != (error ^ SRT_ERR))
		printf("Multiple or no start detected\n");
	if (error != (error ^ END_ERR))
		printf("No end detected\n");
	if (error != (error ^ LNK_ERR))
		printf("Error when linking rooms\n");
	if (error != (error ^ OTH_ERR))
		printf("an unidentified error is detected\n");
}
