/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:57 by sara              #+#    #+#             */
/*   Updated: 2023/06/27 17:59:25 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	keep_last_3(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	go_b;
	int	i;

	size = stack_size(*stack_a);
	go_b = 0;
	i = 0;
	while (size > 6 && i < size && go_b < size / 2)
	{
		if ((*stack_a)->i <= size / 2)
		{
			pb(stack_a, stack_b);
			go_b++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - go_b > 3)
	{
		pb(stack_a, stack_b);
		go_b++;
	}
}

static void	organize_stack(t_stack **stack_a)
{
	int	index_of_smaller_n;
	int	size;
	int	rotations;

	index_of_smaller_n = get_min_index(stack_a);
	size = stack_size(*stack_a);
	if (index_of_smaller_n > size / 2)
	{
		rotations = size - index_of_smaller_n;
		while (rotations > 0)
		{
			rra(stack_a);
			rotations--;
		}
	}
	else
	{
		rotations = index_of_smaller_n;
		while (rotations > 0)
		{
			ra(stack_a);
			rotations--;
		}
	}
}


void	sort(t_stack **stack_a, t_stack **stack_b)
{
	keep_last_3(stack_a, stack_b);
	small_sort(stack_a);
	while (*stack_b)
	{
		find_final_place(stack_a, stack_b);
		cost(stack_a, stack_b);
		least_moves(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		organize_stack(stack_a);
}
