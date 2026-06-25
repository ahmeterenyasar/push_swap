/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:36:48 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:37:33 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	transient;

	if (stack->size < 2)
		return ;
	transient = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = transient;
}

void	sa(t_environment *env)
{
	swap(env->a);
	log_operation(env, "sa");
}

void	sb(t_environment *env)
{
	swap(env->b);
	log_operation(env, "sb");
}

void	ss(t_environment *env)
{
	swap(env->a);
	swap(env->b);
	log_operation(env, "ss");
}
