#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "funcs.h"

void	put_char(char c)
{
	write(1, &c, 1);
}

void	print_m(int m[N][N])
{
	int	x;
	int	y;

	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N)
		{
			put_char(m[y][x] + '0');
			if (x == N - 1)
				put_char('\n');
			else
				put_char(' ');
			x++;
		}
		y++;
	}
}

void	init_m(int m[N][N])
{
	int	x;
	int	y;

	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N)
		{
			m[y][x] = 0;
			x++;
		}
		y++;
	}
}

_Bool	is_valid_index(int row, int column, int val, int m[N][N])
{
	int	i;

	i = column - 1;
	while (i >= 0)
	{
		if (m[row][i] == val)
			return (0);
		i--;
	}
	i = row - 1;
	while (i >= 0)
	{
		if (m[i][column] == val)
			return (0);
		i--;
	}
	return (1);
}

_Bool	brute_force(int index, int m[N][N])
{
	int	val;

	if (index == N * N)
	{
		if (is_valid(m))
		{
			print_m(m);
			return (1);
		}
		return (0);
	}
	val = 1;
	while (val <= N)
	{
		if (!is_valid_index(index / N, index % N, val, m))
		{
			val++;
			continue ;
		}
		m[index / N][index % N] = val;
		if (brute_force(index + 1, m))
			return (1);
		val++;
	}
	return (0);
}
