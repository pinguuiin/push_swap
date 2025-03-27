/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:53:22 by piyu              #+#    #+#             */
/*   Updated: 2025/03/25 17:53:37 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **s, int len)
{
	while (len-- > 0)
		free(s[len]);
	free(s);
}

int	free_list(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	return (1);
}

int	free_array_and_list(int **arr, t_stack **a)
{
	t_stack	*temp;

	free(*arr);
	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	return (0);
}
