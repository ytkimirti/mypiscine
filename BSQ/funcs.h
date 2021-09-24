#ifndef FUNCS_H
# define FUNCS_H 

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFF_FILENAME ".buff"

char	*g_str;

typedef struct s_data
{
	void	*addr;
	char	**map;
	int		row;
	int		column;
	char	mark;
	char	obstacle;
	char	empty;
	int		res_row;
	int		res_column;
	int		res_size;
}t_data;

void	create_buffer_file(void);

void	read_solve_print(t_data *data, char *filename);

void	ft_putstr(char *str);

int		len(char *str);

int		len_endchar(char *str, char endchar);

void	ft_putstr(char *str);

int		read_map_to_str(char *file_name, char **mapstr);

int		read_map_row_count(t_data *data, char **mapstr);

int		read_map_chars(t_data *data, char **mapstr);

int		read_map_lines(t_data *data, char **mapstr);

int		read_map_line(t_data *data, char **mapstr, int line_index);

int		read_map(char *file_name, t_data *data);

void	print_map(t_data *data);

int		find_qr(t_data *map_d);

int		check_printable(char *p);

void	free_data(t_data *data);

#endif
