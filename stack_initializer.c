#include "push_swap.h"

int	free_array_and_list(int **arr, t_stack **a)
{
	t_stack	*temp;

	free(*arr);
	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	return (0);
}

int	stack_initializer(int argc, int **arr, t_stack **a, int len)
{
	int	idx;
	t_stack	*new_node;
	t_stack	*ptr;

	idx = 0;
	ptr = NULL;
	while (idx < len)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return(free_array_and_list(arr, a));
		new_node->index = idx;
		new_node->value = arr[idx];
		new_node->prev = ptr;
		new_node->next = NULL;
		if (idx == 0)
			*a = new_node;
		else
			ptr->next = new_node;
		ptr = new_node;
		idx++;
	}
	free(*arr);
	return (1);
}
