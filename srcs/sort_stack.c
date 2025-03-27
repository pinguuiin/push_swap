/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:51:26 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:51:32 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	both_up(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if ((*b)->cheapest->cost >= (*b)->cheapest->target->cost)
	{
		while (i++ < (*b)->cheapest->target->cost)
			rr(a, b);
		while (i++ < (*b)->cheapest->cost + 1)
			rb(b);
	}
	else
	{
		while (i++ < (*b)->cheapest->cost)
			rr(a, b);
		while (i++ < (*b)->cheapest->target->cost + 1)
			ra(a);
	}
	pa(a, b);
}

static void	both_down(t_stack **a, t_stack **b)
{
	int	i;
	//int	diff_part;

	i = 0;
	if ((*b)->cheapest->cost >= (*b)->cheapest->target->cost)
	{
		//diff_part = (*b)->cheapest->cost - (*b)->cheapest->target->cost;
		while (i++ < (*b)->cheapest->target->cost)
			rrr(a, b);
		while (i++ < (*b)->cheapest->cost + 1)
			rrb(b);
	}
	else
	{
		//diff_part = (*b)->cheapest->target->cost - (*b)->cheapest->cost;
		while (i++ < (*b)->cheapest->cost)
			rrr(a, b);
		while (i++ < (*b)->cheapest->target->cost + 1)
			rra(a);
	}
	pa(a, b);
}

static void	up_down(t_stack **a, t_stack **b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((*b)->cheapest->upper == 1)
	{
		while (i++ < (*b)->cheapest->cost)
			rb(b);
		while (j++ < (*b)->cheapest->target->cost + 1)
			rra(a);
	}
	else
	{
		while (i++ < (*b)->cheapest->cost)
			rrb(b);
		while (j++ < (*b)->cheapest->target->cost + 1)
			ra(a);
	}
	pa(a, b);
}

void	sort_a_rotate(t_stack **a)
{
	t_stack	*min;

	create_index_and_upper(a);
	min = find_min(*a);
	if (min->upper == 1)
	{
		while ((*a) != min)
			ra(a);
	}
	else
	{
		while ((*a) != min)
			rra(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (count_size(*a) <= 3)
	{
		if (count_size(*a) == 2)
			sort_two(a);
		else if (count_size(*a) == 3)
			sort_three(a);
		return ;
	}
	block_sort(a, b);
	sort_three(a);
	// while (*a)
	// {
	// 	ft_putnbr_fd((*a)->value, 1);
	// 	*a = (*a)->next;
	// }
	// return ;

	while (*b)
	{
		stack_stats_initializer(a, b);
		if ((*b)->cheapest->upper == 1 && (*b)->cheapest->target->upper == 1)
			both_up(a, b);
		else if ((*b)->cheapest->upper == 0 && (*b)->cheapest->target->upper == 0)
			both_down(a, b);
		else
			up_down(a, b);
	}
	sort_a_rotate(a);
}
