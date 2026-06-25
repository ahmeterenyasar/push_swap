/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:25:32 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:45:30 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	initialize_environment(t_environment *env, int argc, char **argv)
{
	int	capacity;

	capacity = get_total_capacity(argc, argv);
	if (capacity <= 0)
		return (0);
	env->a = stack_init(capacity);
	env->b = stack_init(capacity);
	if (!env->a || !env->b)
	{
		stack_free(env->a);
		stack_free(env->b);
		return (0);
	}
	env->operation_counter = 0;
	env->print_mode = 1;
	return (1);
}

int	main(int argc, char **argv)
{
	t_environment	env;

	if (argc < 2)
		return (0);
	if (!initialize_environment(&env, argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!parser(env.a, argc, argv) || !has_no_copies(env.a)
		|| !convert_to_indexed(env.a))
	{
		write(2, "Error\n", 6);
		stack_free(env.a);
		stack_free(env.b);
		return (1);
	}
	radix_sort(&env);
	stack_free(env.a);
	stack_free(env.b);
	return (0);
}
