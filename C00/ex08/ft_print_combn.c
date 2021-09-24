#include <unistd.h>

void	ft_putnbr(int a)
{
	int	buff;

	if (a < 0)
	{
		write(1, "-", 1);
		a = -a;
	}
	if (a != 0)
	{
		buff = (a % 10) + '0';
		ft_putnbr(a / 10);
		write(1, &buff, 1);
	}
}

void	print_nums(char *nums, int n)
{
	if (n != 0)
	{
		print_nums(nums + 1, n - 1);
		write(1, nums, 1);
	}
}

void	check_nums(char *nums, int lives, int digit)
{
	if (nums[0] > ('0' + digit) && lives > 0)
	{
		nums[1]++;
		check_nums(nums + 1, lives - 1, digit - 1);
		nums[0] = nums[1] + 1;
	}
}

void	ft_print_combn(int n)
{
	char	nums[11];
	int		i;

	if (n <= 0)
		return ;
	if (n > 9)
		return ;
	i = 0;
	while (i < n)
	{
		nums[i] = '0' - 1 + n - i;
		i++;
	}
	print_nums(nums, n);
	while (1)
	{
		nums[0]++;
		check_nums(nums, n, 9);
		if (nums[n] > 0)
			break ;
		write(1, ", ", 2);
		print_nums(nums, n);
	}
}
