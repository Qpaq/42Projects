#include "ft_select.h"

void	free_args_list(t_args_list *head)
{
	t_args_list		*next;

	while (head)
	{
		ft_memdel((void **)&(head->value));
		ft_memdel((void **)&(head->previous));
		next = head->next;
		ft_memdel((void **)&head);
		head = next;
	}
}

void	free_select_struct(t_select **params)
{
	free_args_list((*params)->list);
	ft_memdel((void **)params);
}

void	return_list(t_select *params)
{
	t_args_list	*current;
	int			space;

	space = 0;
	current = params->list;
	while (current)
	{
		if (space)
			ft_putchar(' ');
		//if (current->selected)
			ft_putstr(current->value);
		current = current->next;
		space = 1;
	}
	free_select_struct(&params);
}

void	print_list(t_select *params)
{
	t_args_list	*current;

	current = params->list;
	while (current)
	{
		ft_putendl(current->value);
		current = current->next;
	}
}

void	parse_arguments(int argc, char **argv, t_select *params)
{
	int			i;
	t_args_list	*new;
	t_args_list	*list;

	list = params->list;
	list->value = ft_strdup(argv[0]);
	params->max_length = ft_strlen(argv[0]);
	i = 1;
	while (i < argc)
	{
		new = (t_args_list *)ft_memalloc(sizeof(t_args_list));
		new->value = ft_strdup(argv[i]);
		list->next = new;
		list = list->next;
		if (params->max_length < ft_strlen(argv[i]))
			params->max_length = ft_strlen(argv[i]);
		i++;
	}
	params->size_list = i;
}
