#include "funcs.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;
	char	*filename;

	filename = 0;
	if (argc == 1)
	{
		create_buffer_file();
		filename = BUFF_FILENAME;
		argc++;
	}
	i = 1;
	while (i < argc)
	{
		if (filename == 0)
			filename = argv[i];
		read_solve_print(&data, filename);
		i++;
		if (i != argc)
			write(1, "\n", 1);
	}
}

void	create_buffer_file(void)
{
	int		buf_file;
	char	c;

	buf_file = open(BUFF_FILENAME, O_RDWR | O_CREAT, 0666);
	while (read(STDIN_FILENO, &c, sizeof(char)) > 0)
	{
		write(buf_file, &c, sizeof(char));
	}
	close(buf_file);
}

void	read_solve_print(t_data *data, char *filename)
{
	int	read_from_stdin;

	read_from_stdin = (filename == 0);
	if (!read_map(filename, data))
		ft_putstr("map error\n");
	else
	{
		find_qr(data);
		print_map(data);
		free_data(data);
	}
}

void	print_map(t_data *data)
{
	int	row;
	int	col;
	int	s;
	int	r;
	int	c;

	s = data->res_size;
	r = data->res_row;
	c = data->res_column;
	row = 0;
	while (row < data->row)
	{
		col = 0;
		while (col < data->column)
		{
			if (row > (r - s) && row <= r && col > (c - s) && col <= c)
				write(1, &(data->mark), 1);
			else
				write(1, &(data->map[row][col]), 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	free_data(t_data *data)
{
	free(data->addr);
	free(data->map);
}
