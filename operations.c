/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-khat <fel-khat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:29:26 by fel-khat          #+#    #+#             */
/*   Updated: 2025/08/12 07:30:58 by fel-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->array[0];
	b->array[0] = b->array[1];
	b->array[1] = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp_a;
	int	temp_b;

	if (a->size >= 2)
	{
		temp_a = a->array[0];
		a->array[0] = a->array[1];
		a->array[1] = temp_a;
	}
	if (b->size >= 2)
	{
		temp_b = b->array[0];
		b->array[0] = b->array[1];
		b->array[1] = temp_b;
	}
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = b->array[0];
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->size--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = a->array[0];
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->size--;
	ft_putstr_fd("pb\n", 1);
}
