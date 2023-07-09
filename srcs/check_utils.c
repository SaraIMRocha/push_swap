/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:49:38 by sara              #+#    #+#             */
/*   Updated: 2023/07/09 04:12:11 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* ft_is_digit:
   Checks if a given character 'c' is a digit (0-9). Returns 1 if it is a digit, 0 otherwise.
*/

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* ft_is_sign:
   Checks if a given character 'c' is a sign ('+' or '-'). Returns 1 if it is a sign, 0 otherwise.
*/

int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}


/* compare_n_str:
   Compares two strings 's1' and 's2' lexicographically, ignoring leading signs.
   Returns an integer value indicating the comparison result:
   - If s1 is less than s2, returns a negative value.
   - If s1 is greater than s2, returns a positive value.
   - If s1 is equal to s2, returns 0.
*/

int	compare_n_str(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
