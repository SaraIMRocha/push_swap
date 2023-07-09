/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:50:01 by sara              #+#    #+#             */
/*   Updated: 2023/07/09 03:27:31 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Swaps the positions of the top two elements in the stack
static void	swap(t_stack *stack)
{
	int	tmp_val;
	int	tmp_i;

	tmp_val = stack->val;
	tmp_i = stack->i;
	if (stack == NULL || stack->next == NULL)
		return ;
	stack->val = stack->next->val;
	stack->i = stack->next->i;
	stack->next->val = tmp_val;
	stack->next->i = tmp_i;
}

// Performs a swap operation on stack A, swapping the top two elements
void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

// Performs a swap operation on stack B, swapping the top two elements
void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

// Performs a swap operation on both stack A and stack B, swapping the top two elements in each
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
