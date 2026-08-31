#include "ft_printf.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL || new == NULL)
		return ;
	temp = ft_lstlast(*lst);
	if (temp == NULL)
		*lst = new;
	else
		temp->next = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = next;
	}
}
