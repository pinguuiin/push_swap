/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:35:36 by piyu              #+#    #+#             */
/*   Updated: 2025/03/19 21:56:55 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_atoi(char *s)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (s[i] == 43 || s[i] == 45)
	{
		sign = 44 - s[i];
		i++;
	}
	while (s[i])
	{
		num = num * 10 + s[i] - '0';
		i++;
	}
	num *= sign;
	return (num);
}

static int	ft_isdup(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	number_check(int argc, char ***argv, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!ft_isnum((*argv)[i]))
		{
			if (argc == 2)
				free_array(*argv, len);
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	save_to_array(int argc, char ***argv, int **arr, int len)
{
	int	i;

	*arr = malloc(len * sizeof(int));
	if (!*arr)
	{
		if (argc == 2)
			free_array(*argv, len);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		(*arr)[i] = ps_atoi((*argv)[i]);
		i++;
	}
	if (argc == 2)
		free_array(*argv, len);
	if (ft_isdup(*arr, len))
	{
		free(*arr);
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	return (1);
}

int	input_check(int argc, char **argv, int **arr, int *len)
{
	*len = 0;
	if (argc <= 1)
		return (0);
	argv++;
	if (argc == 2)
		argv = ft_split(argv[0], ' ');
	if (!argv || !argv[0])
	{
		if (argc == 2 && argv)
			free_array(argv, 1);
		return (0);
	}
	while (argv[*len])
		(*len)++;
	if (!number_check(argc, &argv, *len))
		return (0);
	if (!save_to_array(argc, &argv, arr, *len))
		return (0);
	return (1);
}
