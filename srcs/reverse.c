/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:51 by sara              #+#    #+#             */
/*   Updated: 2023/06/26 03:04:18 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* rev_rotate:
*	Brings the bottom element of a stack to the top.
*/
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

/* rra:
*	Brings the bottom element of stack a to the top.
*	Prints "rra" to the standard output.
*/
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

/* rrb:
*	Brings the bottom element of stack b to the top.
*	Prints "rrb" to the standard output.
*/
void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

/* rrr:
*	Brings the bottom element of both stack a and stack be
*	to the top of their respective stacks.
*	Prints "rrr" to the standard output.
*/
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
