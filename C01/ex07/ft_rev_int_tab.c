void	ft_rev_int_tab(int *tab, int size)
{
	int	left;
	int	right;
	int	c;

	right = size - 1;
	left = 0;
	while (left < right)
	{
		c = tab[left];
		tab[left] = tab[right];
		tab[right] = c;
		left++;
		right--;
	}
}
