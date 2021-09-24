int	ft_sqrt(int nb)
{
	int	n;

	if (nb <= 0)
		return (0);
	n = 1;
	while (n <= 46340)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (0);
}
