#include <unistd.h>

void	ft_putchar(char c);

void	print_char(int is_left, int is_right, int is_top, int is_bottom)
{
	if ((is_left && is_top) || (is_left && is_bottom))
	{
		ft_putchar('o');
	}
	else if ((is_right && is_top) || (is_right && is_bottom))
	{
		ft_putchar('o');
	}
	else if (is_top || is_bottom)
	{
		ft_putchar('-');
	}
	else if (is_right || is_left)
	{
		ft_putchar('|');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int column, int row)
{
	int	x;
	int	y;

	y = 0;
	while (y < row)
	{
		x = 0;
		while (x < column)
		{
			print_char (x == 0, x == column - 1, y == 0, y == row - 1);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
