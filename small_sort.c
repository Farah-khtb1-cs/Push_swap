/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-khat <fel-khat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:30:01 by fel-khat          #+#    #+#             */
/*   Updated: 2025/08/12 10:39:50 by fel-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->array[0];
	second = a->array[1];
	third = a->array[2];
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min_index;
	int	min_value;

	min_index = 0;
	min_value = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] < min_value)
		{
			min_value = stack->array[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	while (a->size > 3)
	{
		min_index = find_min_index(a);
		if (min_index <= a->size / 2)
		{
			while (min_index-- > 0)
				ra(a);
		}
		else
		{
			while (min_index++ < a->size)
				rra(a);
		}
		pb(a, b);
	}
	if (!is_sorted(a))
		sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	handle_small_sorts(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->array[0] > a->array[1])
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
}
