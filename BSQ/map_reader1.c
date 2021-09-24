#include "funcs.h"

int	read_map(char *file_name, t_data *data)
{
	char	*p;
	char	*str;

	if (!read_map_to_str(file_name, &p))
		return (0);
	str = p;
	g_str = p;
	if (!read_map_row_count(data, &p))
		return (0);
	data->map = (char **)malloc(sizeof(char *) * data->row);
	if (!read_map_chars(data, &p))
		return (free(data->map), 0);
	if (!read_map_lines(data, &p))
		return (0);
	free(str);
	return (1);
}

int	read_map_to_str(char *file_name, char **mapstr)
{
	int		len;
	int		state;
	char	c;
	int		file;

	file = open(file_name, O_RDONLY);
	len = 0;
	state = read(file, &c, sizeof(char));
	while (state > 0)
		(len++, state = read(file, &c, sizeof(char)));
	if (state == -1)
		return (0);
	(*mapstr) = (char *)malloc((len + 1) * sizeof(char));
	close(file);
	file = open(file_name, O_RDONLY);
	len = 0;
	state = 10;
	while (state > 0)
	{
		state = read(file, &c, sizeof(char));
		if (state == -1)
			return (free(*mapstr), 0);
		(*mapstr)[len++] = c;
	}
	return (1);
}

// Reads the row count from top of the file
// Returns 1 on success
// Return 0 on fail
int	read_map_row_count(t_data *data, char **mapstr)
{
	int		sum;
	char	*p;

	p = *mapstr;
	sum = 0;
	while (*p != 0)
	{
		if (*p >= '0' && *p <= '9')
		{
			sum = (*p - '0') + (sum * 10);
		}
		else
		{
			data->row = sum;
			if (data->row <= 0)
				return (0);
			*mapstr = p;
			return (1);
		}	
		p++;
	}
	return (0);
}

int	read_map_chars(t_data *data, char **mapstr)
{
	char	*p;

	p = *mapstr;
	if (len_endchar(p, '\n') != 3)
		return (0);
	if (p[0] == p[1] || p[0] == p[2] || p[1] == p[2])
		return (0);
	if (!check_printable(p))
		return (0);
	data->empty = p[0];
	data->obstacle = p[1];
	data->mark = p[2];
	p += 4;
	*mapstr = p;
	return (1);
}
