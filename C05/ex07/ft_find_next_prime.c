int	ft_find_next_prime(int nb)
{
	int	index;

	index = 2;
	if (nb <= 2)
		return (2);
	while (nb < 2147483647)
	{
		index = 2;
		while (nb % index != 0)
		{
			if (index >= nb / 2)
				return (nb);
			index++;
		}
		nb++;
	}
	return (2147483647);
}
