#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>

# define ARG_SET char **str, va_list *args, int *result

int	ft_printf(char *str, ...);

#endif
