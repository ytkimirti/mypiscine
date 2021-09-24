#include "funcs.h"

void	update_cell(t_data *map_c, int x, int y)
{
	map_c->map[y][x] = map_c->map[y - 1][x - 1] + 1;
	if (map_c->map[y][x] > map_c->map[y - 1][x])
		map_c->map[y][x] = map_c->map[y - 1][x] + 1;
	if (map_c->map[y][x] > map_c->map[y][x - 1])
		map_c->map[y][x] = map_c->map[y][x - 1] + 1;
}

void	scan_map(t_data *map_d, t_data *map_c)
{
	int		x;
	int		y;
	char	max;

	max = 0;
	y = 0;
	while (++y < map_c->row)
	{
		x = 0;
		while (++x < map_c->column)
		{	
			if (map_d->map[y - 1][x - 1] == map_d->empty)
			{
				update_cell(map_c, x, y);
				if (max < map_c->map[y][x])
				{
					max = map_c->map[y][x];
					map_d->res_row = y - 1;
					map_d->res_column = x - 1;
					map_d->res_size = max;
				}
			}
		}
	}
}

void	init_map(t_data *map_c)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_c->row)
	{
		x = 0;
		while (x < map_c->column)
		{
			map_c->map[y][x] = 0;
			x++;
		}
		y++;
	}
}

t_data	*give_me_mem(t_data *map_d)
{
	int		y;
	t_data	*map_c;

	map_c = malloc(sizeof(t_data));
	map_c->map = malloc(sizeof(char *) * (map_d->row + 1));
	map_c->addr = malloc((map_d->row + 1) * (map_d->column + 1) * sizeof(char));
	map_c->row = map_d->row + 1;
	map_c->column = map_d->column + 1;
	y = 0;
	while (y < map_c->row)
	{
		map_c->map[y] = map_c->addr + (sizeof(char) * map_c->column * y);
		y++;
	}
	init_map(map_c);
	return (map_c);
}

int	find_qr(t_data *map_d)
{
	t_data	*map_c;

	map_c = give_me_mem(map_d);
	scan_map(map_d, map_c);
	free(map_c->addr);
	free(map_c->map);
	free(map_c);
	return (1);
}
