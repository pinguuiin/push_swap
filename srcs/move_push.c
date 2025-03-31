/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:50:30 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:50:36 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **lst1, t_stack **lst2)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	if (*lst1)
	{
		ptr1 = *lst1;
		ptr2 = *lst2;
		*lst1 = (*lst1)->next;
		if (*lst1)
			(*lst1)->prev = NULL;
		if (*lst2)
			ptr2->prev = ptr1;
		ptr1->next = ptr2;
		*lst2 = ptr1;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}
