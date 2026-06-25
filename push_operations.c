/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:25:28 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:40:50 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dest, t_stack *src)
{
	int	shift_idx;
	int	popped_top;

	if (src->size == 0)
		return ;
	popped_top = src->data[0];
	shift_idx = 0;
	while (shift_idx < src->size - 1)
	{
		src->data[shift_idx] = src->data[shift_idx + 1];
		shift_idx++;
	}
	src->size--;
	shift_idx = dest->size;
	while (shift_idx > 0)
	{
		dest->data[shift_idx] = dest->data[shift_idx - 1];
		shift_idx--;
	}
	dest->data[0] = popped_top;
	dest->size++;
}

void	pa(t_environment *env)
{
	push(env->a, env->b);
	log_operation(env, "pa");
}

void	pb(t_environment *env)
{
	push(env->b, env->a);
	log_operation(env, "pb");
}
