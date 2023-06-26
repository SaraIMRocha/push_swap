/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:40 by sara              #+#    #+#             */
/*   Updated: 2023/06/26 03:00:51 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* add_vals_stack:
*	Fills stack_a with the provided values.
*	If the values are out of integer range, prints and error and exits the program.
*/
t_stack	*add_vals_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error(&stack_a, NULL);
		if (i == 1)
			stack_a = create_new_stack((int)nb);
		else
			add_at_the_end(&stack_a, create_new_stack((int)nb));
		i++;
	}
	return (stack_a);
}

/* give_place:
*	Assigns an index to each value in stack a. This is a convenient way to order
*	the stack because indexes can be checked and compared instead of actual values,
*	which may or may not be adjacent to each other.
*		ex. values:		-3	 0	 9	 2
*		indexes:		[1]	[2]	[4]	[3]
*	The indexes are assigned from big_index (size) to lowest (1).
*/
void	give_place(t_stack *stack_a, int size)
{
	t_stack	*ptr;
	t_stack	*big_index;
	int		value;

	while (--size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		big_index = NULL;
		while (ptr)
		{
			if (ptr->val == INT_MIN && ptr->i == 0)
				ptr->i = 1;
			if (ptr->val > value && ptr->i == 0)
			{
				value = ptr->val;
				big_index = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (big_index != NULL)
			big_index->i = size;
	}
}
