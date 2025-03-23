#include "push_swap.h"

void	block_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	size;

	i = 0;
	size = count_size(*a);
	while (i < size)
	{
		if ((*a)->block == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
	i = 0;
	while (i < size - size / 3 - 1)
	{
		if ((*a)->block == 1)
			pb(a,  b);
		else
			ra(a);
		i++;
	}
	while ((*a)->next->next->next)
		pb(a, b);
}

void	push_b_to_a


void	sort_stack(t_stack **a, t_stack **b)
{
	block_sort(a, b);
	sort_three(a);
}
