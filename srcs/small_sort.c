/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:55 by sara              #+#    #+#             */
/*   Updated: 2023/06/26 03:06:29 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* get_big_index:
*	Returns the max_index index in a stack.
*/
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

/* small_sort:
*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
*	rather than value. Example:
*		values:		 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solution, 2 moves:
*	rra:
*		values:		 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		values:		 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/
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
