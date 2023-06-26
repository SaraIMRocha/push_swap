/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:50:01 by sara              #+#    #+#             */
/*   Updated: 2023/06/26 03:28:58 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* swap:
*	Swaps the top 2 elements of a stack.
*	Does nothing if there is only one or no elements.
*/
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

/* sa:
*	Swaps the top 2 elements of stack a.
*	Prints "sa" to the standard output.
*/
void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

/* sb:
*	Swaps the top 2 elements of stack b.
*	Prints "sb" to the standard output.
*/
void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

/* ss:
*	Swaps the top 2 elements of stack a and the top 2 elements
*	of stack b.
*	Prints "ss" to the standard output.
*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
