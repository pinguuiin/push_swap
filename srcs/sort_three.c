/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:53:55 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:54:00 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_max_index(t_stack *lst)
{
	t_stack	*max;

	max = lst;
	while (lst)
	{
		if (lst->value > max->value)
			max = lst;
		lst = lst->next;
	}
	return (max->index);
}

void	sort_three(t_stack **lst)
{
	int	max;

	create_index_and_upper(lst);
	max = calculate_max_index(*lst);
	if (max == 0)
	{
		ra(lst);
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
