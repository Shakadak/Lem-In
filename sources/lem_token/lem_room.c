#include <stdlib.h>
#include "lem-in.h"
#include "libft.h"

static char		**ft_strtrimsplit(char *line);
static void		free_tab(char ***tab);
static t_lroom	*new_room(char **src, t_lroom *current);
static void		new_coo(char **src, t_lroom *current);

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
				new_coo(tmp, current);
			map->next = TBASIC;
			if (map->next == TSTART || map->next == TEND)
				current->type = map->next;
		}
	}
}

static t_lroom	*new_room(char **src, t_lroom *current)
{
	t_lroom		*new;

	new = (t_lroom *)malloc(sizeof(t_lroom));
	new->next = current;
	new->name = ft_strdup(src[0]);
	new->type = TBASIC;
	new_coo(src, new);
	new->link = NULL;
}

static void		new_coo(char **src, t_lroom *current)
{
	current->coo.x = ft_atoi(src[1]);
	current->coo.y = ft_atoi(src[2]);
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

static void		free_tab(char ***tab)
{
	free(*tab[0]);
	free(*tab[1]);
	free(*tab[2]);
	free(*tab);
	*tab = NULL;
}
