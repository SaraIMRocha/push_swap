/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:40 by sara              #+#    #+#             */
/*   Updated: 2023/06/27 17:52:24 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
