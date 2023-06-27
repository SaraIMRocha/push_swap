/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:55 by sara              #+#    #+#             */
/*   Updated: 2023/06/27 17:53:39 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_big_index(t_stack *stack)
{
	int		index;

	index = stack->i;
	while (stack)
	{
		if (stack->i > index)
			index = stack->i;
		stack = stack->next;
	}
	return (index);
}

void	small_sort(t_stack **stack)
{
	int		max_index;

	if (is_sorted(*stack))
		return ;
	max_index = get_big_index(*stack);
	if ((*stack)->i == max_index)
		ra(stack);
	else if ((*stack)->next->i == max_index)
		rra(stack);
	if ((*stack)->i > (*stack)->next->i)
		sa(stack);
}
