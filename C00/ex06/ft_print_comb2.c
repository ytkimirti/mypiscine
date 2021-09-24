#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	print_num(int a)
{
	if (a < 10)
	{
		write(1, "0", 1);
	}
	else
	{
		putchar((a / 10) + '0');
	}
	putchar((a % 10) + '0');
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 1;
	b = 0;
	while (b < 99)
	{
		print_num(b);
		putchar(' ');
		print_num(a);
		if (!(b == 98 && a == 99))
			write(1, ", ", 2);
		a++;
		if (a == 100)
		{
			b++;
			a = b + 1;
		}
	}
}
