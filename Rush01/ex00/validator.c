#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "funcs.h"

_Bool	is_valid(int m[N][N])
{
	return (check_rows(m) && check_columns(m));
}

_Bool	check_rows(int m[N][N])
{
	int	i;
	int	line[N];
	int	j;

	i = 0;
	while (i < N * 2)
	{
		j = -1;
		if (i < N)
		{
			while (++j < N)
				line[j] = m[i][j];
		}
		else
		{
			while (++j < N)
				line[j] = m[i - N][N - 1 - j];
		}
		if (!check_line_dups(line))
			return (0);
		else if (!check_line_order(g_args[i + N * 2], line))
			return (0);
		i++;
	}
	return (1);
}

_Bool	check_columns(int m[N][N])
{
	int	i;
	int	line[N];
	int	j;

	i = 0;
	while (i < N * 2)
	{
		j = -1;
		if (i < N)
		{
			while (++j < N)
				line[j] = m[j][i];
		}
		else
		{
			while (++j < N)
				line[j] = m[N - 1 - j][i - N];
		}
		if (!check_line_dups(line) || !check_line_order(g_args[i], line))
			return (0);
		i++;
	}
	return (1);
}

_Bool	check_line_dups(int *line)
{
	int	i;
	int	j;

	i = 0;
	while (i < N - 1)
	{
		j = i + 1;
		while (j < N)
		{
			if (line[i] == line[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

_Bool	check_line_order(int n, int *line)
{
	int	max;
	int	count;
	int	i;

	count = 1;
	max = line[0];
	i = 1;
	while (i < N)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count == n);
}
