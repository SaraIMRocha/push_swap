/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:59 by sara              #+#    #+#             */
/*   Updated: 2023/07/09 03:25:08 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Returns the last element in the stack
t_stack	*get_last_value(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

// Returns the penultimate (second-to-last) element in the stack
t_stack	*get_penultimate(t_stack *stack)
{
	int	size;
	int	i;

	size = stack_size(stack);
	i = -1;
	while (++i < size - 2)
		stack = stack->next;
	return (stack);
}

// Creates a new stack element with the specified value and initializes its attributes
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

// Adds a new stack element at the end of the stack
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

// Returns the size (number of elements) in the stack
int	stack_size(t_stack	*stack)
{
	int		size;
	t_stack	*current;

	size = 1;
	current = stack->next;
	if (stack == NULL)
		return (0);
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}
