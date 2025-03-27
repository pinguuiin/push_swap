/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:51:01 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:51:08 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *s)
{
	int	i;
	int	sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (!*s)
		return (0);
	if (s[i] == 43 || s[i] == 45)
	{
		sign = 44 - s[i];
		i++;
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		else
			num = num * 10 + (s[i] - '0');
		if ((num > INT_MAX && sign == 1) || num - 1 > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	count_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	calculate_min(t_stack *lst)
{
	int	min;

	min = lst->value;
	while (lst)
	{
		if (lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	return (min);
}

int	calculate_max(t_stack *lst)
{
	int	max;

	max = lst->value;
	while (lst)
	{
		if (lst->value > max)
			max = lst->value;
		lst = lst->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *lst)
{
	t_stack	*min;

	min = lst;
	while (lst)
	{
		if (lst->value < min->value)
			min = lst;
		lst = lst->next;
	}
	return (min);
}
