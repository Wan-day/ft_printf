#include "ft_printf.h"

int	ft_print_num(char **str, va_list *args, int *result)
{
	char	*temp;

	temp = ft_itoa(va_arg(*args, int));
	if (temp == NULL)
		return (-1);
	while (*temp)
	{
		if (write(1, *temp, 1) == -1)
			return (-1);
		temp++;
		*result++;
	}
	*str += 2;
	free (temp);
	return (0);
}

int	ft_print_str(char **str, va_list *args, int *result, int test)
{
	char	*temp;

	if (test == 1)
	{
		if (write (1, "%", 1) == -1)
			return (-1);
		*str += 2;
		*result++;
	}
	else
	{
		temp = va_arg(*args, char *);
		while (*temp)
		{
			if (write(1, temp, 1) == -1)
				return (-1);
			temp++;
			*result++;
		}
		*str += 2;
	}
}
