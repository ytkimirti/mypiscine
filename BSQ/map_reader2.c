#include "funcs.h"

int	read_map_lines(t_data *data, char **mapstr)
{
	char	*p;
	int		line_index;
	int		y;

	p = *mapstr;
	data->column = len_endchar(p, '\n');
	line_index = 0;
	if (data->column <= 0)
		return (0);
	data->addr = malloc(data->row * data->column * sizeof(char));
	y = 0;
	while (y < data->row)
	{
		data->map[y] = data->addr + (sizeof(char) * data->column * y);
		y++;
	}
	while (line_index < data->row)
	{
		if (!read_map_line(data, &p, line_index))
			return (free(data->addr), 0);
		line_index++;
	}
	return (1);
}

int	read_map_line(t_data *data, char **mapstr, int line_index)
{
	char	*p;
	int		i;

	p = *mapstr;
	i = 0;
	while (*p != 0)
	{
		if (*p == '\n')
			return (*mapstr = p + 1, i == data->column);
		if (*p != data->empty && *p != data->obstacle)
			return (0);
		if (i >= data->column)
			return (0);
		data->map[line_index][i++] = *p;
		p++;
	}
	return (0);
}
