/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:47 by sara              #+#    #+#             */
/*   Updated: 2023/06/29 06:35:18 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_place(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->place = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_min_index(t_stack **stack)
{
	t_stack	*tmp;
	int		small_index;
	int		low_place;

	tmp = *stack;
	small_index = INT_MAX;
	get_place(stack);
	low_place = tmp->place;
	while (tmp)
	{
		if (tmp->i < small_index)
		{
			small_index = tmp->i;
			low_place = tmp->place;
		}
		tmp = tmp->next;
	}
	return (low_place);
}

static int	find_smaller_index(t_stack **a, int b_idx,
								int num_index, int num_place)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->i > b_idx && tmp_a->i < num_index)
		{
			num_index = tmp_a->i;
			num_place = tmp_a->place;
		}
		tmp_a = tmp_a->next;
	}
	if (num_index != INT_MAX)
		return (num_place);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->i < num_index)
		{
			num_index = tmp_a->i;
			num_place = tmp_a->place;
		}
		tmp_a = tmp_a->next;
	}
	return (num_place);
}

void	find_final_place(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_place(a);
	get_place(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = find_smaller_index(a, tmp_b->i, INT_MAX, target_pos);
		tmp_b->final_place = target_pos;
		tmp_b = tmp_b->next;
	}
}
