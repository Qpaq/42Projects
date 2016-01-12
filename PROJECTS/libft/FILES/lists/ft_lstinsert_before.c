#include "libft.h"

void	ft_lstinsert_before(t_list **alst, t_list *target, t_list *new)
{
  t_list  *previous;
  t_list  *node;
  
  node = *alst;
  previous = *alst;
  while (node)
  {
    if (node == target)
    {
      new->next = target;
      previous->next = new;
    }
    previous = node;
    node = node->next;
  }
}
