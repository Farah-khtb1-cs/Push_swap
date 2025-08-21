/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-khat <fel-khat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 07:32:03 by fel-khat          #+#    #+#             */
/*   Updated: 2025/08/12 10:48:09 by fel-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int		*array;
	int		size;
	int		capacity;
}	t_stack;

void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

t_stack		*init_stack(int capacity);
void		free_stack(t_stack *stack);
int			is_sorted(t_stack *stack);
void		print_error(void);

int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_strlen(const char *str);

int			parse_arguments(int argc, char **argv, t_stack *stack);
int			is_valid_number(const char *str);
int			has_duplicates(t_stack *stack);

void		normalize_stack(t_stack *stack);
void		radix_sort(t_stack *a, t_stack *b);
int			get_max_bits(t_stack *stack);

void		sort_three(t_stack *a);
void		sort_five(t_stack *a, t_stack *b);
int			find_min_index(t_stack *stack);

char		**ft_split(char *str, char *charset);
void		free_split(char **split);
int			check_int_limits(const char *str);
long		ft_atol(const char *str);
int			add_number_to_stack(const char *str, t_stack *stack);
int			parse_single_string(char *str, t_stack *stack);
void		handle_small_sorts(t_stack *a, t_stack *b);
int			init_stacks(t_stack **a, t_stack **b, int size);

#endif