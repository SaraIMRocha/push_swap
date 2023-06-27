/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:36 by sara              #+#    #+#             */
/*   Updated: 2023/06/27 17:52:08 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_if_number(char *argv)
{
	int	i;

	i = 0;
	if (ft_is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_is_digit(argv[i]))
		return (0);
	return (1);
}

static int	check_if_repeated(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && compare_n_str(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_zeros(char *argv)
{
	int	i;

	i = 0;
	if (ft_is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	is_correct_input(char **argv)
{
	int	i;
	int	zero;

	zero = 0;
	i = 1;
	while (argv[i])
	{
		if (!check_if_number(argv[i]))
			return (0);
		zero += check_zeros(argv[i]);
		i++;
	}
	if (zero > 1)
		return (0);
	if (check_if_repeated(argv))
		return (0);
	return (1);
}
