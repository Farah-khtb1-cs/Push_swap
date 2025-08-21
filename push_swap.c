/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-khat <fel-khat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:29:38 by fel-khat          #+#    #+#             */
/*   Updated: 2025/08/12 07:31:09 by fel-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stack **a, t_stack **b, int size)
{
	*a = init_stack(size);
	*b = init_stack(size);
	if (!*a || !*b)
	{
		free_stack(*a);
		free_stack(*b);
		return (0);
	}
	return (1);
}

static int	parse_and_validate(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (!parse_arguments(argc, argv, a))
	{
		print_error();
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!init_stacks(&a, &b, argc - 1))
		return (1);
	if (!parse_and_validate(argc, argv, a, b))
		return (0);
	if (a->size <= 5)
		handle_small_sorts(a, b);
	else
	{
		normalize_stack(a);
		radix_sort(a, b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
