/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:50:05 by sara              #+#    #+#             */
/*   Updated: 2023/07/09 03:17:04 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* rr_a_and_b:
 * Performs rotating reverse operations on stacks A and B until both cost_a and
 * cost_b become non-negative. This adjusts the positions of objects in both
 * stacks to match their desired final positions.
 */


static void	rr_a_and_b(t_stack **a, t_stack **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

/* r_a_and_b:
 * Performs rotating operations on stacks A and B until both cost_a and cost_b
 * become non-positive. This adjusts the positions of objects in both stacks
 * to match their desired final positions.
 */

static void	r_a_and_b(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

/* r_a:
 * Performs rotating operations on stack A until the cost becomes zero. This
 * adjusts the position of an object in stack A to match its desired final
 * position.
 */

static void	r_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

/* r_b:
 * Performs rotating operations on stack B until the cost becomes zero. This
 * adjusts the position of an object in stack B to match its desired final
 * position.
 */


static void	r_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

/* which_move:
 * Determines the appropriate move(s) based on the values of cost_a and cost_b,
 * and performs the necessary rotations on stacks A and B to adjust the
 * positions of objects. Finally, it pushes the top object from stack B to
 * stack A.
 */

void	which_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rr_a_and_b(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		r_a_and_b(a, b, &cost_a, &cost_b);
	r_a(a, &cost_a);
	r_b(b, &cost_b);
	pa(a, b);
}
