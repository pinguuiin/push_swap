/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:50:09 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:50:18 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **lst)
{
	t_stack	*ptr1;
	t_stack	*ptr2;

	if (*lst && (*lst)->next)
	{
		ptr1 = *lst;
		ptr2 = *lst;
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
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
