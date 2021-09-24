#include <unistd.h>

void	rush(int a, int b);

int	main(void)
{
	rush(5, 3);
	write(1, "\n\n", 2);
	rush(5, 1);
	write(1, "\n\n", 2);
	rush(1, 1);
	write(1, "\n\n", 2);
	rush(1, 5);
	write(1, "\n\n", 2);
	rush(4, 4);
}
