/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-khat <fel-khat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:29:57 by fel-khat          #+#    #+#             */
/*   Updated: 2025/08/12 07:31:28 by fel-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[a->size - 1] = temp;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->array[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[b->size - 1] = temp;
	ft_putstr_fd("rb\n", 1);
}

static void	rotate_stack(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size >= 2)
	{
		temp = stack->array[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[stack->size - 1] = temp;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putstr_fd("rr\n", 1);
}
