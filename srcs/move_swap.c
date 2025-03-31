/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:48:36 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:48:44 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (ptr2->next)
			ptr2->next->prev = ptr1;
		ptr2->next = ptr1;
		*lst = ptr2;
	}
}

void	sa(t_stack **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
