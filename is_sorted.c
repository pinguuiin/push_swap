#include "push_swap.h"

int	free_list(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	return (1);
}

int	is_sorted(t_stack **a)
{
	t_stack	*ptr;

	ptr = *a;
	if (ptr && !ptr->next)
		return (free_list(a));
	while (ptr && ptr->next)
	{
		if (ptr->value > ptr->next->value)
			return(0);
		ptr = ptr->next;
	}
	return (free_list(a));
}
