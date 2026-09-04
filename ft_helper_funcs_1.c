#include "ft_printf.h"

int	ft_parse_arg(char **str, va_list *args, int *result)
{
	if (!str[1])
		return (-1);
	else if (str[1] == i || str[i] == d)
		return (ft_print_num(ARG_SET));
	else if (str[1] == s || str[1] == c)
		return (ft_print_str(ARG_SET, 0));
	else if (str[1] == p)
		return (ft_print_ptr(ARG_SET));
	else if (str[1] == u)
		return (ft_print_unsigned(ARG_SET));
	else if (str[1] == x)
		return (ft_print_hex(ARG_SET, 0));
	else if (str[1] == X)
		return (ft_print_hex(ARG_SET, 1));
	else if (str[1] == %)
		return (ft_print_str(ARG_SET, 1));
	else 
		return (-1);
}
