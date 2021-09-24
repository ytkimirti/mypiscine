#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int	val;
	int				buff;

	val = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		val = -nb;
	}
	if (nb != 0)
	{
		buff = (val % 10) + '0';
		ft_putnbr(val / 10);
		write(1, &buff, 1);
	}
}
