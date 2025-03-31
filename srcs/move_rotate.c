/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:48:56 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:49:56 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
