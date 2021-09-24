#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "funcs.h"

int	g_args[N * 4];

int	print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		m[N][N];
	int		i;
	char	*str;

	init_m(m);
	if (argc != 2)
		return (print_error());
	str = argv[1];
	i = 0;
	while (str[i] != 0)
	{
		if (i % 2 == 0)
		{
			if (str[i] < '0' || str[i] > '9')
				return (print_error());
			g_args[i / 2] = str[i] - '0';
		}
		else if (str[i] != ' ')
			return (print_error());
		i++;
	}
	if (str[N * 8 - 1] != '\0')
		return (print_error());
	if (!brute_force(0, m))
		return (print_error());
}
