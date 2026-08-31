#include "ft_printf.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

char	*ft_strchr(char *s, int c)
{
	unsigned char		test;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	test = (unsigned char)c;
	while (*str)
	{
		if (*str == test)
			return ((char *)s);
		str++;
		s++;
	}
	if (*str == test)
		return ((char *)s);
	else
		return (NULL);
}

ssize_t	ft_find_arg(char *str, char *set)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]) != NULL)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *str)
{
	char	*result;
	int		i;

	i = 0;
	while(str[i])
		i++;
	result = malloc((i + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_split(char **str, int index)
{
	char	*new;
	char	*old;
	int		i;

	if (str == NULL || *str == NULL || index < 0)
		return (NULL);
	new = malloc((index + 1) * sizeof(char));
	if (new == NULL)
		return (NULL)
	old = ft_strdup(*str + index);
	if (old == NULL)
	{
		free(new);
		return (NULL);
	}
	i = 0;
	while (i < index)
	{
		new[i] = (*str)[i];
		i++;
	}
	new[i] = '\0';
	free(*str);
	*str = old;
	return (new);
}
