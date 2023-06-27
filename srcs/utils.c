/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:50:04 by sara              #+#    #+#             */
/*   Updated: 2023/06/27 17:54:32 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		ft_free(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		ft_free(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

long int	ft_atoi(const char *str)
{
	long int	num;
	int			signal;
	int			i;

	num = 0;
	signal = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signal = -1;
		i++;
	}
	while (ft_is_digit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * signal);
}
