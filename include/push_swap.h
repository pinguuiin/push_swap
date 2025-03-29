/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:38:49 by piyu              #+#    #+#             */
/*   Updated: 2025/03/19 21:50:22 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				upper;
	int				block;
	int				block_divider;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	calculate_block_divider(t_stack **lst);
void	create_blocks(t_stack **lst);
void	block_sort(t_stack **a, t_stack **b, int divider);
void	free_array(char **s, int len);
int		free_list(t_stack **a);
int		free_array_and_list(int **arr, t_stack **a);
int		input_check(int argc, char **argv, int **arr, int *len);
void	push(t_stack **lst1, t_stack **lst2);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **lst);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rotate(t_stack **lst);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	swap(t_stack **lst);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		is_sorted(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **lst);
void	sort_two(t_stack **lst);
void	create_index_and_upper(t_stack **lst);
void	stack_stats_initializer(t_stack **a, t_stack **b);
int		ft_isnum(char *s);
int		count_size(t_stack *lst);
int		calculate_min(t_stack *lst);
int		calculate_max(t_stack *lst);
t_stack	*find_min(t_stack *lst);

#endif
