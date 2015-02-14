#include "wolf3d.h"

void		get_map(t_env *e)
{
	int		fd;
	int		nbl;
	char	**map;
	char	*line;
	int		i;

	nbl = 0;
	fd = open(MAP_FILE, O_RDONLY);
	sleep(5);
	while (get_next_line(fd, &line) > 0)
	{
		nbl++;
		free(line);
	}
	free(line);
	close(fd);
	map = (char **)malloc(sizeof(char *) * (nbl + 1));

	sleep(5);
	i = 0;
	fd = open(MAP_FILE, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map[i] = NULL;
	free(line);
	close(fd);
	e->map = map;
}