#include "funcs.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	len_endchar(char *str, char endchar)
{
	int	i;

	i = 0;
	while (str[i] != endchar)
	{
		if (str[i] == 0)
			return (-1);
		i++;
	}		
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}

int	check_printable(char *p)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (p[i] < ' ' || p[i] > '~')
			return (0);
		i++;
	}
	return (1);
}
