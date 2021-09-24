unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int				len;
	unsigned int	i;

	len = 0;
	while (src[len] != 0)
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while (*src != 0 && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len);
}
