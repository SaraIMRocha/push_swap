/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:32 by sara              #+#    #+#             */
/*   Updated: 2023/06/26 03:31:42 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <ctype.h>

typedef struct s_stack
{
	int				val;
	int				i;
	int				place;
	int				final_place;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Initialization */

t_stack		*add_vals_stack(int ac, char **av);
void		give_place(t_stack *stack_a, int ac);

/* Sorting Algorithms */

int			is_sorted(t_stack *stack);
void		small_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Position  */

int			get_min_index(t_stack **stack);
void		find_final_place(t_stack **stack_a, t_stack **stack_b);

/* Cost */

void		cost(t_stack **stack_a, t_stack **stack_b);
void		least_moves(t_stack **stack_a, t_stack **stack_b);

/* Calculate Move */
void		which_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Operations */

void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);

/* Stack Functions */

t_stack		*get_last_value(t_stack *stack);
t_stack		*get_penultimate(t_stack *stack);
t_stack		*create_new_stack(int value);
void		add_at_the_end(t_stack **stack, t_stack *new);
int			stack_size(t_stack	*stack);

/* Utils */

void		ft_free(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);

/* Error */

void		ft_error(t_stack **stack_a, t_stack **stack_b);

/* Input Check */

int			is_correct_input(char **av);
int			ft_is_digit(char c);
int			ft_is_sign(char c);
int			compare_n_str(const char *s1, const char *s2);

#endif
