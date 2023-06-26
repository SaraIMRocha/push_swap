/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:47 by sara              #+#    #+#             */
/*   Updated: 2023/06/26 03:00:19 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* get_place:
*	Assigns a placeitio
n to each element of a stack from top to bottom
*	in ascending order.
*	Example stack:
*		value:		 3	 0	 9	 1
*		index:		[3]	[1]	[4]	[2]
*		position:	<0>	<1>	<2>	<3>
*	This is used to calculate the cost of moving a certain number to
*	a certain position. If the above example is stack b, it would cost
*	nothing (0) to push the first element to stack a. However if we want to
*	push the highest value, 9, which is in third position, it would cost 2 extra
*	moves to bring that 9 to the top of b before pushing it to stack a.
*/
static void	get_place(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->place = i;
		tmp = tmp->next;
		i++;
	}
}

/* get_min_index:
*	Gets the current position of the element with the lowest index
*	within a stack.
*/
int	get_min_index(t_stack **stack)
{
	t_stack	*tmp;
	int		small_index;
	int		low_place;

	tmp = *stack;
	small_index = INT_MAX;
	get_place(stack);
	low_place = tmp->place;
	while (tmp)
	{
		if (tmp->i < small_index)
		{
			small_index = tmp->i;
			low_place = tmp->place;
		}
		tmp = tmp->next;
	}
	return (low_place);
}

/* find_smaller_index:
*	Picks the best target position in stack A for the given index of
*	an element in stack B. First checks if the index of the B element can
*	be placed somewhere in between elements in stack A, by checking whether
*	there is an element in stack A with a bigger index. If not, it finds the
*	element with the smallest index in A and assigns that as the target position.
*	--- Example:
*		final_place starts at INT_MAX
*		B index: 3
*		A contains indexes: 9 4 2 1 0
*		9 > 3 && 9 < INT_MAX 	: final_place updated to 9
*		4 > 3 && 4 < 9 			: target pos updated to 4
*		2 < 3 && 2 < 4			: no update!
*	So final_place needs to be the position of index 4, since it is
*	the closest index.
*	--- Example:
*		final_place starts at INT_MAX
*		B index: 20
*		A contains indexes: 16 4 3
*		16 < 20					: no update! final_place = INT_MAX
*		4  < 20					: no update! final_place = INT_MAX
*		3  < 20					: no update! final_place = INT_MAX
*	... final_place stays at INT MAX, need to switch strategies.
*		16 < 20					: final_place updated to 20
*		4  < 20					: final_place updated to 4
*		3  < 20					: final_place updated to 3
*	So final_place needs to be the position of index 3, since that is
*	the "end" of the stack.
*/
static int	find_smaller_index(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->i > b_idx && tmp_a->i < target_idx)
		{
			target_idx = tmp_a->i;
			target_pos = tmp_a->place;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->i < target_idx)
		{
			target_idx = tmp_a->i;
			target_pos = tmp_a->place;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* find_final_place:
*	Assigns a target position in stack A to each element of stack A.
*	The target position is the spot the element in B needs to
*	get to in order to be sorted correctly. This position will
*	be used to calculate the cost of moving each element to
*	its target position in stack A.
*/
void	find_final_place(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_place(a);
	get_place(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = find_smaller_index(a, tmp_b->i, INT_MAX, target_pos);
		tmp_b->final_place = target_pos;
		tmp_b = tmp_b->next;
	}
}
