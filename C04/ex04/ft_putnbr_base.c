#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

_Bool	is_valid(char *charset, int len)
{
	int	stat;
	int	i;

	stat = 0;
	if (charset[0] == 0 || charset[1] == 0)
		return (0);
	while (stat < len)
	{
		if (charset[stat] == '+' || charset[stat] == '-')
			return (0);
		i = 0;
		while (i < len)
		{
			if (i != stat && charset[i] == charset[stat])
			{
				return (0);
			}
			i++;
		}
		stat++;
	}
	return (1);
}

void	rec_func(int nbr, char *charset, int len)
{
	unsigned int	val;

	if (nbr < 0)
	{
		ft_putchar('-');
		val = -nbr;
	}
	else
	{
		val = nbr;
	}
	if (val >= (unsigned int) len)
		rec_func(val / len, charset, len);
	ft_putchar(charset[val % len]);
}

void	ft_putnbr_base(int nbr, char *charset)
{
	int	len;

	len = 0;
	while (charset[len] != 0)
		len++;
	if (!is_valid(charset, len))
		return ;
	rec_func(nbr, charset, len);
}
