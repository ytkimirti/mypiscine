#include <stdio.h>
#include <unistd.h>

_Bool	is_valid(int row, int col);

int	g_p[10];

int	g_c;

void	print_p(void)
{
	int		i;
	char	buffer;

	i = 0;
	while (i < 10)
	{
		buffer = g_p[i] + '0';
		write(1, &buffer, 1);
		i++;
	}
	write(1, "\n", 1);
	g_c++;
}

_Bool	brute_force(int col)
{
	int	row;

	if (col == 10)
	{
		print_p();
		return (0);
	}
	row = 0;
	while (row < 10)
	{
		if (is_valid(row, col))
		{
			g_p[col] = row;
			brute_force(col + 1);
		}
		row++;
	}
	return (0);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

_Bool	is_valid(int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (g_p[i] == row)
			return (0);
		if (abs(i - col) == abs(g_p[i] - row))
			return (0);
		i++;
	}
	return (1);
}

int	ft_ten_queens_puzzle(void)
{
	g_c = 0;
	brute_force(0);
	return (g_c);
}
