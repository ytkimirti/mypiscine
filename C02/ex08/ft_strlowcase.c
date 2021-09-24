char	*ft_strlowcase(char *str)
{
	char	*mem;

	mem = str;
	while (*str != 0)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
		}
		str++;
	}
	return (mem);
}
