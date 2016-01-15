#include "ft_ls.h"

void		free_one(t_files *head)
{
	if (head)
	{
		if (head->permissions)
			ft_memdel((void **)&head->permissions);
	//	if (head->owner)
	//		free(head->owner);
	//	if (head->group)
	//		free(head->group);
		if (head->date)
			ft_memdel((void **)&head->date);
		if (head->name)
			ft_memdel((void **)&head->name);
		if (head->parent_dir)
			ft_memdel((void **)&head->parent_dir);
		ft_memdel((void **)&head);
	}
}

void		free_list(t_files *head)
{
	t_files	*next;

	while (head)
	{
		next = head->next;
		free_one(head);
		head = next;
	}
}

void		free_main_struct(t_ls_args *args)
{
	ft_memdel((void **)&args->authorized_options);
	ft_memdel((void **)&args->options);
}
