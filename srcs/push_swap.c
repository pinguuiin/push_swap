/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:57:30 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:58:06 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_initializer(int **arr, t_stack **a, int len)
{
	int		idx;
	t_stack	*new_node;
	t_stack	*ptr;

	idx = 0;
	ptr = NULL;
	while (idx < len)
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (free_array_and_list(arr, a));
		new_node->index = idx;
		new_node->value = (*arr)[idx];
		new_node->prev = ptr;
		new_node->next = NULL;
		if (idx == 0)
			*a = new_node;
		else
			ptr->next = new_node;
		ptr = new_node;
		idx++;
	}
	free(*arr);
	return (1);
}

int	is_sorted(t_stack **a)
{
	t_stack	*ptr;

	ptr = *a;
	if (ptr && !ptr->next)
		return (free_list(a));
	while (ptr && ptr->next)
	{
		if (ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (free_list(a));
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		len;
	t_stack	*a;
	t_stack	*b;

	len = 0;
	arr = NULL;
	a = NULL;
	b = NULL;
	if (!input_check(argc, argv, &arr, &len))
		return (0);
	if (!stack_initializer(&arr, &a, len))
		return (0);
	if (is_sorted(&a))
		return (0);
	sort_stack(&a, &b);
	free_list(&a);
	free_list(&b);
	return (0);
}
