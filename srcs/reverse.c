/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:51 by sara              #+#    #+#             */
/*   Updated: 2023/07/09 03:50:34 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Reverses the rotation of the stack by moving the last element to the beginning
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last_element;
	t_stack	*penultimate;

	last_element = get_last_value(*stack);
	penultimate = get_penultimate(*stack);
	tmp = *stack;
	*stack = last_element;
	(*stack)->next = tmp;
	penultimate->next = NULL;
}

// Reverses the rotation of stack A by moving the last element to the beginning
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

// Reverses the rotation of stack B by moving the last element to the beginning
void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

// Reverses the rotation of both stack A and stack B by moving their last elements to the beginning
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
