#include "ft_printf.h"

void	*ft_printf(char	*str, ...)
{
	va_list	args;
	ssize_t	arg_index;
	t_list	*str_arr;
	char	*temp;


	arg_index = ft_find_arg(str, ARG_SET);
	if (arg_index == -1)
	{
		ft_putstr(str);
		return ;
	}
	temp = ft_split(str, arg_index);
	str_arr = ft_lstnew(temp);
	va_start(argc, str);



	va_end(argc);
}
