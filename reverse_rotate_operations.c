/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:39:47 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:40:12 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	x;

	x = stack->data[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = x;
}

void	rra(t_environment *env)
{
	reverse_rotate(env->a);
	log_operation(env, "rra");
}

void	rrb(t_environment *env)
{
	reverse_rotate(env->b);
	log_operation(env, "rrb");
}

void	rrr(t_environment *env)
{
	reverse_rotate(env->a);
	reverse_rotate(env->b);
	log_operation(env, "rrr");
}
