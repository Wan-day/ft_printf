#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define ARG_SET "cspdiuxX%"

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

void	ft_printf(char *str, ...);

#endif
