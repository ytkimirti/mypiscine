char	*ft_strupcase(char *str)
{
	char	*mem;

	mem = str;
	while (*str != 0)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str -= 32;
		}
		str++;
	}
	return (mem);
}
