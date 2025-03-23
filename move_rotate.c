#include "push_swap.h"

void	rotate(t_stack **lst)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	if (*lst && (*lst)->next)
	{
		ptr1 = *lst;
		ptr2 = ptr1;
		while (ptr2->next)
			ptr2 = ptr2->next;
		*lst = (*lst)->next;
		(*lst)->prev = NULL;
		ptr2->next = ptr1;
		ptr1->prev = ptr2;
		ptr1->next = NULL;
	}
}
void	ra(t_stack **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
