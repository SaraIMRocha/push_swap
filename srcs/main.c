/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:42 by sara              #+#    #+#             */
/*   Updated: 2023/07/09 04:00:43 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Checks if the given stack is sorted in ascending order
// Returns 1 if the stack is sorted, 0 otherwise

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Executes the appropriate push and sort operations to perform the push_swap algorithm
// Receives the stacks 'stack_a' and 'stack_b' and the size of 'stack_a'
// If 'stack_size' is 2 and 'stack_a' is not sorted, performs 'sa' operation
// If 'stack_size' is 3, performs 'small_sort' operation on 'stack_a'
// If 'stack_size' is greater than 3 and 'stack_a' is not sorted, performs 'sort'
// operation on 'stack_a' and 'stack_b'

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		small_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

// Entry point of the program
// Receives the command line arguments 'ac' and 'av'
// Creates the stacks 'stack_a' and 'stack_b' from the input values
// Validates the input with 'is_correct_input' function and handles errors with 'ft_error' function
// Executes the push_swap algorithm with 'push_swap' function passing 'stack_a', 'stack_b', and 'size'
// Frees the memory allocated for 'stack_a' and 'stack_b' using 'ft_free' function
// Returns 0 to indicate successful execution

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		ft_error(NULL, NULL);
	stack_b = NULL;
	stack_a = add_vals_stack(ac, av);
	size = stack_size(stack_a);
	give_place(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
