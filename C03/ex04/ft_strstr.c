char	*ft_strstr(char *str, char *to_find)
{
	int	a;
	int	i;

	a = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[a] != '\0')
	{
		i = 0;
		while (str[a + i] == to_find[i] && str[a + i] != '\0')
		{
			if (to_find[i + 1] == '\0')
				return (&str[a]);
			i++;
		}
		a++;
	}
	return (0);
}
