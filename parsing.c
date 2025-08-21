/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-khat <fel-khat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:29:31 by fel-khat          #+#    #+#             */
/*   Updated: 2025/08/12 10:49:27 by fel-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_single_string(char *str, t_stack *stack)
{
	char	**numbers;
	int		i;

	numbers = ft_split(str, " \n\t\v\r\f");
	if (!numbers || !numbers[0])
	{
		free_split(numbers);
		return (0);
	}
	i = 0;
	while (numbers[i])
	{
		if (!add_number_to_stack(numbers[i], stack))
		{
			free_split(numbers);
			return (0);
		}
		i++;
	}
	free_split(numbers);
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack)
{
	int	i;

	if (argc == 2)
	{
		if (!parse_single_string(argv[1], stack))
			return (0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!add_number_to_stack(argv[i], stack))
				return (0);
			i++;
		}
	}
	return (!has_duplicates(stack));
}
