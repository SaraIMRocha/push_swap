/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:57 by sara              #+#    #+#             */
/*   Updated: 2023/06/26 04:37:25 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* keep_last_3:
*	Pushes all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency.
*/
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

/* organize_stack:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/
static void	organize_stack(t_stack **stack_a)
{
	int	min_index;
	int	size;
	int	i;

	min_index = get_min_index(stack_a);
	size = stack_size(*stack_a);
	i = 0;
	if (min_index > size / 2)
	{
		while (min_index < size)
		{
			rra(stack_a);
			min_index++;
		}
	}
	else
	{
		while (i < min_index)
		{
			ra(stack_a);
			i++;
		}
	}
}

/* sort:
*	Sorting algorithm for a stack larger than 3.
*		Push everything but 3 numbers to stack B.
*		Sort the 3 numbers left in stack A.
*		Calculate the most cost-effective move.
*		Shift elements until stack A is in order.
*/
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
