/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:51:31 by piyu              #+#    #+#             */
/*   Updated: 2025/04/04 01:51:36 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_block_divider(t_stack **lst)
{
	int		size;
	int		divider;
	t_stack	*ptr;

	ptr = *lst;
	size = count_size(*lst);
	if (size <= 100)
		divider = 3;
	else if (size <= 300)
		divider = 4;
	else
		divider = 5;
	while (ptr)
	{
		ptr->block_divider = divider;
		ptr = ptr->next;
	}
}

static int	get_tertile_first(t_stack *lst, int tertile)
{
	int		num;
	int		size;
	t_stack	*ptr;

	num = 0;
	size = count_size(lst);
	tertile--;
	while (num < size / lst->block_divider)
	{
		num = 0;
		ptr = lst;
		tertile++;
		while (ptr)
		{
			if (ptr->value < tertile)
				num++;
			ptr = ptr->next;
		}
	}
	return (tertile);
}

static int	get_tertile_second(t_stack *lst, int tertile1, int tertile2)
{
	int		num;
	int		size;
	t_stack	*ptr;

	num = 0;
	size = count_size(lst);
	tertile2--;
	while (num < size / lst->block_divider)
	{
		num = 0;
		ptr = lst;
		tertile2++;
		while (ptr)
		{
			if (ptr->value >= tertile1 && ptr->value < tertile2)
				num++;
			ptr = ptr->next;
		}
	}
	return (tertile2);
}

static void	create_blocks(t_stack **lst)
{
	int		min;
	int		size;
	int		tertile[2];
	t_stack	*ptr;

	ptr = *lst;
	min = calculate_min(*lst);
	size = count_size(*lst);
	tertile[0] = get_tertile_first(*lst, min + size / ptr->block_divider);
	tertile[1] = get_tertile_second(*lst, tertile[0], tertile[0] + \
		size / ptr->block_divider);
	while (ptr)
	{
		if (ptr->value < tertile[0])
			ptr->block = 0;
		else if (ptr->value >= tertile[0] && ptr->value < tertile[1])
			ptr->block = 1;
		else
			ptr->block = 2;
		ptr = ptr->next;
	}
}

void	block_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	counter;

	create_blocks(a);
	i = count_size(*a);
	counter = 0;
	while (count_size(*a) > (*a)->block_divider && i > 0)
	{
		if ((*a)->block < 2)
		{
			pb(a, b);
			if ((*b)->block == 1)
				counter++;
			if ((*b)->block == 0 && counter > 0)
				rb(b);
		}
		else
			ra(a);
		i--;
	}
	if (count_size(*a) > (*a)->block_divider)
		block_sort(a, b);
	while (count_size(*a) > 3)
		pb(a, b);
}
