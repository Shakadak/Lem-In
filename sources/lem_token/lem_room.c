#include <stdlib.h>
#include "lem-in.h"
#include "libft.h"

static char		**ft_strtrimsplit(char *line)

void	lem_room(t_map *map, char *line)
{
	char	**line;
	t_lroom	*current;

	if (map->next == TLINK)
		map->next = TSTOP;
	else
	{
		tmp = ft_strtrimsplit(line);
		if (!full_digit(tmp[1]) || !full_digit(tmp[2]))
			lem_error(map, tmp);
		else
		{
			if ((current = get_room(tmp[0])) == NULL)
			{
				map->map = new_room(tmp, map->map);
				current = map->map;
			}
			else
				current->coo = new_coo(tmp);
			map->next = TBASIC;
			if (map->next == TSTART || map->next == TEND)
				current->type = map->next;
		}
	}
}

static char		**ft_strtrimsplit(char *line)
{
	char	**tmp;
	char	*tmp2;
	tmp2 = ft_strtrim(line);
	tmp = ft_strsplit(tmp2, ' ');
	free(tmp2);
	return (tmp);
}
