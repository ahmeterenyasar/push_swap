/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:37:50 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:39:10 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	i;
	int	x;

	x = stack->data[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->size - 1] = x;
}

void	ra(t_environment *env)
{
	rotate(env->a);
	log_operation(env, "ra");
}

void	rb(t_environment *env)
{
	rotate(env->b);
	log_operation(env, "rb");
}

void	rr(t_environment *env)
{
	rotate(env->a);
	rotate(env->b);
	log_operation(env, "rr");
}
