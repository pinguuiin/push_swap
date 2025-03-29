/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:55:29 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:55:53 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_index_and_upper(t_stack **lst)
{
	int	i;
	int	size;
	t_stack	*ptr;

	i = 0;
	size = count_size(*lst);
	ptr = *lst;
	while (ptr)
	{
		ptr->index = i;
		if (i <= size / 2)
			ptr->upper = 1;
		else
			ptr->upper = 0;
		ptr = ptr->next;
		i++;
	}
}

static void	find_target(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	ptr_a = *a;
	ptr_b = *b;
	while (ptr_b)
	{
		target = NULL;
		ptr_a = *a;
		while (ptr_a)
		{
			if (!target && ptr_a->value > ptr_b->value)
				target = ptr_a;
			if (target && ptr_a->value > ptr_b->value && ptr_a->value < target->value)
				target = ptr_a;
			ptr_a = ptr_a->next;
		}
		if (!target)
			target = find_min(*a);
		ptr_b->target = target;
		ptr_b = ptr_b->next;
	}
}

static void	calculate_cost(t_stack **lst)
{
	int	i;
	int	size;
	t_stack	*ptr;

	i = 0;
	size = count_size(*lst);
	ptr = *lst;
	while (ptr)
	{
		if (ptr->upper == 1)
			ptr->cost = i;
		else
			ptr->cost = size - i;
		ptr = ptr->next;
		i++;
	}
}

static void	calculate_cheapest(t_stack **b)
{
	t_stack	*ptr;
	t_stack	*cheapest;

	ptr = *b;
	cheapest = *b;
	while (ptr)
	{
		// if (ptr->cost + ptr->target->cost < cheapest->cost + cheapest->target->cost)
			// cheapest = ptr;
		if (ptr->cost + ptr->target->cost <= cheapest->cost + cheapest->target->cost + 4 && ptr->value > cheapest->value)
			cheapest = ptr;
		ptr = ptr->next;
	}
	ptr = *b;
	while (ptr)
	{
		ptr->cheapest = cheapest;
		ptr = ptr->next;
	}
}

void	stack_stats_initializer(t_stack **a, t_stack **b)
{
	create_index_and_upper(a);
	create_index_and_upper(b);
	//create_blocks(a);
	calculate_cost(a);
	calculate_cost(b);
	find_target(a, b);
	calculate_cheapest(b);
}
