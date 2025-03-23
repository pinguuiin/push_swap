#include "push_swap.h"

void	reverse_rotate(t_stack **lst)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	if (*lst && (*lst)->next)
	{
		ptr1 = *lst;
		ptr2 = ptr1;
		while (ptr2->next)
			ptr2 = ptr2->next;
		ptr2->prev->next = NULL;
		ptr2->prev = NULL;
		ptr2->next = ptr1;
		ptr1->prev = ptr2;
		*lst = ptr2;
	}
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
}
