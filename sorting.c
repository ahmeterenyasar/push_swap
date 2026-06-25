/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:25:42 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:49:18 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_environment *env)
{
	int	*numbers;

	numbers = env->a->data;
	if (numbers[0] > numbers[1] && numbers[1] < numbers[2]
		&& numbers[2] > numbers[0])
		sa(env);
	else if (numbers[0] > numbers[1] && numbers[1] > numbers[2])
	{
		sa(env);
		rra(env);
	}
	else if (numbers[0] > numbers[1] && numbers[2] < numbers[0])
		ra(env);
	else if (numbers[0] < numbers[1] && numbers[1] > numbers[2]
		&& numbers[2] > numbers[0])
	{
		sa(env);
		ra(env);
	}
	else if (numbers[0] < numbers[1] && numbers[2] < numbers[0])
		rra(env);
}

void	small_sort(t_environment *env)
{
	int	items_to_move;
	int	smallest_now;

	if (env->a->size == 2)
	{
		if (env->a->data[0] > env->a->data[1])
			sa(env);
		return ;
	}
	items_to_move = env->a->size - 3;
	smallest_now = 0;
	while (smallest_now < items_to_move)
	{
		to_top(env, smallest_now);
		pb(env);
		smallest_now++;
	}
	sort_three(env);
	while (env->b->size > 0)
	{
		pa(env);
	}
}

static void	process_radix_bit(t_environment *env, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((env->a->data[0] >> bit) & 1) == 0)
			pb(env);
		else
			ra(env);
		i++;
	}
}

void	radix_sort(t_environment *env)
{
	int	bit;
	int	total_bits;

	if (is_sorted(env->a))
		return ;
	if (env->a->size <= 5)
	{
		small_sort(env);
		return ;
	}
	total_bits = get_max_bits(env->a->size);
	bit = 0;
	while (bit < total_bits)
	{
		process_radix_bit(env, bit, env->a->size);
		while (env->b->size > 0)
			pa(env);
		bit++;
	}
}
