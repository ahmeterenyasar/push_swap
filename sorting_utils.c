/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:48:18 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:48:44 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	to_top(t_environment *env, int wanted_number)
{
	int	current_location;
	int	total_items;
	int	inverse_distance;

	current_location = 0;
	while (env->a->data[current_location] != wanted_number)
	{
		current_location++;
	}
	total_items = env->a->size;
	if (current_location <= (total_items / 2))
	{
		while (current_location-- > 0)
			ra(env);
	}
	else
	{
		inverse_distance = total_items - current_location;
		while (inverse_distance-- > 0)
			rra(env);
	}
}

int	get_max_bits(int n)
{
	int	bits;
	int	max_val;

	bits = 0;
	max_val = n - 1;
	while (max_val > 0)
	{
		max_val >>= 1;
		bits++;
	}
	return (bits);
}
