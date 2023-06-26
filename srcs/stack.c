/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:59 by sara              #+#    #+#             */
/*   Updated: 2023/06/26 03:25:46 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* get_last_value:
*	Returns the last element of the stack.
*/
t_stack	*get_last_value(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* get_penultimate:
*	Returns the second to last element of the stack.
*/
t_stack	*get_penultimate(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/* create_new_stack:
*	Creates a stack elements with the provided value.
*	Returns the newly created stack element.
*/
t_stack	*create_new_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->val = value;
	new->i = 0;
	new->place = -1;
	new->final_place = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/* add_stack_bottom:
*	Adds an element to the bottom of a stack.
*/
void	add_at_the_end(t_stack **stack, t_stack *new)
{
	t_stack	*last_value;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last_value = get_last_value(*stack);
	last_value->next = new;
}

/* stack_size:
*	Returns the number of elements in a stack.
*/
int	stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
