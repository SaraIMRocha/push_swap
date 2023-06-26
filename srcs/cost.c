/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:44 by sara              #+#    #+#             */
/*   Updated: 2023/06/26 02:08:25 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

/* least_moves:
*	Finds the element in stack B with the cheapest cost to move to stack A
*	and moves it to the correct placeition in stack A.
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
