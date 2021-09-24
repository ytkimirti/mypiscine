int	len(char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}

char	*ft_strcat(char *dest, char *src)
{
	int	mylen;

	mylen = len(dest);
	while (*src != '\0')
	{
		dest[mylen] = *src;
		mylen++;
		src++;
	}
	dest[mylen] = '\0';
	return (dest);
}
