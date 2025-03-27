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

static void	find_target(t_stack *a, t_stack **b)
{
	t_stack	*min;
	t_stack	*target;
	t_stack	*ptr;

	ptr = *b;
	min = find_min(a);
	while (ptr)
	{
		target = NULL;
		while (a)
		{
			if (!target && a->value > ptr->value)
				target = a;
			if (target && a->value > ptr->value && a->value < target->value)
				target = a;
			a = a->next;
		}
		if (!target)
			target = min;
		// if (!target)
		// 	ft_putstr_fd("Here!", 1);
		ptr->target = target;
		ptr = ptr->next;
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
	int	cost_total;
	t_stack	*ptr;
	t_stack	*cheapest;

	ptr = *b;
	cheapest = *b;
	cost_total = ptr->cost + ptr->target->cost;

	// ft_putnbr_fd(ptr->cost, 1);
	// ft_putnbr_fd(ptr->target->cost, 1);
	// return;
	while (ptr)
	{
		// if (!ptr->target)
		// 	ft_putstr_fd("Here!", 1);
		ptr->cheapest = NULL;
		if (ptr->cost + ptr->target->cost < cost_total)
			cheapest = ptr;
		ptr = ptr->next;
	}
	(*b)->cheapest = cheapest;
}

void	stack_stats_initializer(t_stack **a, t_stack **b)
{
	create_index_and_upper(a);
	create_index_and_upper(b);
	create_blocks(a);
	calculate_cost(a);
	calculate_cost(b);
	find_target(*a, b);
	calculate_cheapest(b);
}
