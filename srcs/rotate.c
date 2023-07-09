/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:53 by sara              #+#    #+#             */
/*   Updated: 2023/07/09 03:49:48 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Rotates the stack by moving the first element to the end
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last_element;

	tmp = *stack;
	*stack = (*stack)->next;
	last_element = get_last_value(*stack);
	tmp->next = NULL;
	last_element->next = tmp;
}

// Rotates stack A by moving the first element to the end
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

// Rotates stack B by moving the first element to the end
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

// Rotates both stack A and stack B by moving their first elements to the end
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
