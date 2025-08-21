/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-khat <fel-khat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:29:19 by fel-khat          #+#    #+#             */
/*   Updated: 2025/08/12 07:30:51 by fel-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_stack_to_array(t_stack *stack, int *sorted)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		sorted[i] = stack->array[i];
		i++;
	}
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	replace_with_index(t_stack *stack, int *sorted)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->array[i] == sorted[j])
			{
				stack->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	normalize_stack(t_stack *stack)
{
	int	*sorted;

	sorted = malloc(sizeof(int) * stack->size);
	if (!sorted)
		return ;
	copy_stack_to_array(stack, sorted);
	sort_array(sorted, stack->size);
	replace_with_index(stack, sorted);
	free(sorted);
}

int	get_max_bits(t_stack *stack)
{
	int	max_num;
	int	max_bits;

	max_num = stack->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
