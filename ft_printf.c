#include "ft_printf.h"

int	ft_printf(char	*str, ...)
{
	va_list	args;
	ssize_t	arg_index;
	int		result;

	result = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_parse_arg(&str, &args, &result) == -1)
				return (-1);
		}
		else
		{
			if (!ft_putchar(*str))
				return (-1);
			result++;
		}
	}
	va_end(args);
	return (result);
}
