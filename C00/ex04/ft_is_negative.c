#include <unistd.h>

void	ft_is_negative(int n)
{
	char	character;

	if (n < 0)
	{
		character = 78;
	}
	else
	{
		character = 'P';
	}
	write(1, &character, 1);
}
