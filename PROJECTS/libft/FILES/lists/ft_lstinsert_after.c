#include "libft.h"

void	ft_lstinsert_after(t_list **alst, t_list *target, t_list *new)
{
	if (*alst)
	{
		if (!target)
			ft_lstadd_end(alst, new);
		else
		{
			new->next = target->next;
			target->next = new;
		}
	}
}
