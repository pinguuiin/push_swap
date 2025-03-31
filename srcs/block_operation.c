/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:52:05 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:52:20 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_tertile_first(t_stack *lst, int tertile)
{
	int		num;
	int		size;
	t_stack	*ptr;

	num = 0;
	size = count_size(lst);
	tertile--;
	while (num < size / 3)
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
	while (num < size / 3)
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

void	create_blocks(t_stack **lst)
{
	int		min;
	int		size;
	int		tertile[2];
	t_stack	*ptr;

	ptr = *lst;
	min = calculate_min(*lst);
	size = count_size(*lst);
	tertile[0] = get_tertile_first(*lst, min + size / 3);
	tertile[1] = get_tertile_second(*lst, tertile[0], tertile[0] + size / 3);
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
	while (count_size(*a) > 3 && i > 0)
	{
		if ((*a)->block == 1)
		{
			pb(a, b);
			counter++;
		}
		else if ((*a)->block == 0)
		{
			pb(a, b);
			if (counter)
				rb(b);
		}
		else
			ra(a);
		i--;
	}
	if (count_size(*a) > 3)
		block_sort(a, b);
}
