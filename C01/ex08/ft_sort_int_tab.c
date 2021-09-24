void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	current;

	i = 1;
	while (i < size)
	{
		current = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > current)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = current;
		i++;
	}
}
