#include "push_swap.h"

int	min(t_stack *lst)
{
	int	min_val;

	min_val = 0;
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			min_val = lst->next->index;
		lst = lst->next;
	}
	return (min_val);
}

int	max(t_stack *lst)
{
	int	max_val;

	max_val = 0;
	while (lst && lst->next)
	{
		if (lst->value < lst->next->value)
			max_val = lst->next->index;
		lst = lst->next;
	}
	return (max_val);
}

void	sort_three(t_stack **lst)
{
	int	max;

	max = calculate_max(*lst);
	if (max == 0)
	{
		ra(lst); ////////////////////////////////////////////
		if ((*lst)->value > (*lst)->next->value)
			sa(lst);
	}
	else if (max == 1)
	{
		rra(lst);
		if ((*lst)->value > (*lst)->next->value)
			sa(lst);
	}
	else
	{
		if ((*lst)->value > (*lst)->next->value)
			sa(lst);
	}
}

void	sort_two(t_stack **lst)
{
	if ((*lst)->value > (*lst)->next->value)
		sa(lst);
}
