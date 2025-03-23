#include "push_swap.h"

void	swap(t_stack **lst)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	if (*lst && (*lst)->next)
	{
		ptr1 = *lst;
		ptr2 = (*lst)->next;
		ptr1->next = ptr2->next;
		ptr2->prev = ptr1->prev;
		ptr1->prev = ptr2;
		ptr2->next = ptr1;
		*lst = ptr2;
	}
}
void	sa(t_stack **a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
