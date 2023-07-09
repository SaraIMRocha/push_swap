/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:44 by sara              #+#    #+#             */
/*   Updated: 2023/07/09 04:04:22 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Assigns cost values to each element in 'stack_b' based on its 'place' and 'final_place' values
 * 'size_a' and 'size_b' represent the sizes of 'stack_a' and 'stack_b' respectively
 * Iterates through each element in 'stack_b' and calculates the cost values:
 *   - 'cost_b' is assigned the value of 'place'
 *   - If 'place' is in the upper half of 'stack_b', 'cost_b' is multiplied by -1 to indicate
 *	 	a negative cost
 *   - 'cost_a' is assigned the value of 'final_place'
 *   - If 'final_place' is in the upper half of 'stack_a', 'cost_a' is multiplied by -1
 *  	to indicate a negative cost
*/

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = stack_size(tmp_a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->place;
		if (tmp_b->place > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->place) * -1;
		tmp_b->cost_a = tmp_b->final_place;
		if (tmp_b->final_place > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->final_place) * -1;
		tmp_b = tmp_b->next;
	}
}

/* Finds the element in 'stack_b' with the least total cost ('cheapest') calculated from
 * 'cost_a' and 'cost_b' values
 * 'cost_a' and 'cost_b' store the cost values of the selected element with the least total cost
 * Iterates through each element in 'stack_b', comparing the absolute sum of 'cost_a' and 'cost_b'
 * with 'cheapest'
 * Updates 'cheapest', 'cost_a', and 'cost_b' with the values of the element with the least total cost
 * Calls 'which_move' function to perform the necessary moves based on the selected element's cost values
*/

void	least_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs(tmp->cost_a) + abs(tmp->cost_b) < abs(cheapest))
		{
			cheapest = abs(tmp->cost_b) + abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	which_move(stack_a, stack_b, cost_a, cost_b);
}
