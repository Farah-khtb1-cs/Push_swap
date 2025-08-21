/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-khat <fel-khat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:30:16 by fel-khat          #+#    #+#             */
/*   Updated: 2025/08/12 07:31:49 by fel-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->array[i] == stack->array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int_limits(const char *str)
{
	long	num;

	num = ft_atol(str);
	return (num >= INT_MIN && num <= INT_MAX);
}

int	add_number_to_stack(const char *str, t_stack *stack)
{
	long	num;

	if (!is_valid_number(str))
		return (0);
	if (!check_int_limits(str))
		return (0);
	num = ft_atol(str);
	stack->array[stack->size] = (int)num;
	stack->size++;
	return (1);
}
