#include <unistd.h>

void	ft_print(char c)
{
	write(1, &c, 1);
}

void	ft_print_nums(int a, int b, int c, char is_last)
{
	ft_print(c + '0');
	ft_print(b + '0');
	ft_print(a + '0');
	if (!is_last)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int		a;
	int		b;
	int		c;
	char	is_last;

	a = 9;
	b = 0;
	c = 0;
	while (!(c == 7 && b == 8 && a == 9))
	{
		a++;
		if (a == 10)
		{
			b++;
			a = b + 1;
		}
		if (b == 9)
		{
			c++;
			b = c + 1;
			a = c + 2;
		}
		is_last = c == 7 && b == 8 && a == 9;
		ft_print_nums(a, b, c, is_last);
	}
}
