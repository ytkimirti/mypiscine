#ifndef FUNCS_H

# define FUNCS_H

# define N 4

int	g_args[N * 4];

int	g_n;

_Bool	is_valid(int m[N][N]);

_Bool	check_line_order(int n, int *line);

_Bool	check_line_dups(int *line);

_Bool	brute_force(int index, int m[N][N]);

void	put_char(char c);

_Bool	is_valid_index(int row, int column, int val, int m[N][N]);

void	print_m(int m[N][N]);

void	init_m(int m[N][N]);

_Bool	check_rows(int m[N][N]);

_Bool	check_columns(int m[N][N]);

#endif
