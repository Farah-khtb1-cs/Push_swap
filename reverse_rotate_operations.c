/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-khat <fel-khat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:29:53 by fel-khat          #+#    #+#             */
/*   Updated: 2025/08/12 07:31:23 by fel-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->array[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = temp;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->array[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = temp;
	ft_putstr_fd("rrb\n", 1);
}

static void	reverse_rotate_stack(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size >= 2)
	{
		temp = stack->array[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[0] = temp;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_putstr_fd("rrr\n", 1);
}
