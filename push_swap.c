/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:29:29 by piyu              #+#    #+#             */
/*   Updated: 2025/03/19 21:57:59 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*arr;
	int	len;
	t_stack	*a;
	t_stack	*b;

	len = 0;
	arr = NULL;
	a = NULL;
	b = NULL;
	if (!input_check(argc, argv, &arr, &len));
		return (0);
	if (!stack_initializer(argc, &arr, &a, len));
		return (0);
	if (is_sorted(&a))
		return (0);
	sort_stack(&a, &b);
	return (0);
}
