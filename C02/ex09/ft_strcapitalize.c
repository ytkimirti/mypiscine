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

char	is_alpha(char *c)
{
	return (!((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z')));
}

char	is_empty_char(char *c)
{
	return ((*c < '0' || *c > '9') && is_alpha(c));
}

char	*ft_strcapitalize(char *str)
{
	char	*mem;

	mem = str;
	str = ft_strlowcase(str);
	if (*str >= 'a' && *str <= 'z')
	{
		*(str) -= 32;
	}
	while (*str != 0)
	{
		if (is_empty_char(str) && (*(str + 1) >= 'a' && *(str + 1) <= 'z'))
		{
			*(str + 1) -= 32;
		}
		str++;
	}
	return (mem);
}
