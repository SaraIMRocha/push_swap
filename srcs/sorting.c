/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:57 by sara              #+#    #+#             */
/*   Updated: 2023/07/09 03:19:21 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * keep_last_3: Moves elements from stack A to stack B, keeping the last 3 elements in stack A.
 *              Elements are moved based on their value compared to the size of stack A.
 *              If the element's value is less than or equal to half the size of stack A,
 *              it is moved to stack B. Otherwise, the element is rotated to the top of stack A.
 * @param stack_a: Pointer to stack A.
 * @param stack_b: Pointer to stack B.
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

/**
 * organize_stack: Organizes stack A by rotating elements until the smallest element is at the top.
 *                 If the index of the smallest element is in the bottom half of the stack,
 *                 it is rotated in the reverse direction to bring it to the top.
 *                 Otherwise, it is rotated in the regular direction to bring it to the top.
 * @param stack_a: Pointer to stack A.
 */

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

/**
 * sort: Sorts the elements in stack A in ascending order.
 *       The function uses various helper functions to perform the sorting algorithm.
 *       1. Moves the last 3 elements from stack A to stack B using keep_last_3 function.
 *       2. Sorts the remaining elements in stack A using the small_sort function.
 *       3. Iteratively finds the final place for elements in stack B, calculates their costs,
 *          and performs the least moves to move them from stack B to stack A.
 *       4. If stack A is not already sorted, organizes it by rotating elements until the
 *			smallest element is at the top.
 * @param stack_a: Pointer to stack A.
 * @param stack_b: Pointer to stack B.
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
