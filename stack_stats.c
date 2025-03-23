#include "push_swap.h"

void	create_index_and_upper(t_stack **lst)
{
	int	i;
	int	size;
	t_stack	*ptr;

	i = 0;
	size = count_size(*lst);
	ptr = *lst;
	while (ptr)
	{
		ptr->index = i;
		if (i <= size / 2)
			ptr->upper = 1;
		else
			ptr->upper = 0;
		ptr = ptr->next;
		i++;
	}
}

int	count_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	create_blocks(t_stack **lst)
{
	int	i;
	int	min_val;
	int	block_size;
	t_stack	*ptr;

	i = 0;
	ptr = *lst;
	min_val = min(*lst);
	block_size = (max(*lst) - min(*lst)) / 3 + 1;
	while (ptr)
	{
		ptr->block = (ptr->value - min_val) / block_size;
		ptr = ptr->next;
	}
}

void	find_target(t_stack *a, t_stack **b)
{
	t_stack	*target;
	t_stack	*ptr;

	ptr = *b;
	while (ptr)
	{
		target = NULL;
		while (a)
		{
			if (!target && a->value > ptr->value)
				target = a;
			if (target && a->value > ptr->value && a->value < target->value)
				target = a;
			a = a->next;
		}
		ptr->target = target;
		ptr = ptr->next;
	}
}

void	calculate_cost(t_stack **lst)
{
	int	i;
	int	size;
	t_stack	*ptr;

	i = 0;
	size = count_size(*lst);
	ptr = *lst;
	while (ptr)
	{
		if (ptr->upper == 1)
			ptr->cost = i;
		else
			ptr->cost = size - i;
		i++;
	}
}

void	calculate_cheapest(t_stack *a, t_stack **b)
{
	int	i;
	int	cost;
	t_stack	*ptr;

	ptr = *b;
	while (ptr)
	{
	}
}
