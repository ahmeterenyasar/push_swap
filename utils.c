/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:25:56 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:40:58 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_no_copies(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->data[i] == a->data[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	convert_to_indexed(t_stack *a)
{
	int	i;
	int	j;
	int	smaller_count;
	int	*new_arr;

	new_arr = malloc(sizeof(int) * a->size);
	if (!new_arr)
		return (0);
	i = 0;
	while (i < a->size)
	{
		smaller_count = 0;
		j = 0;
		while (j < a->size)
		{
			if (a->data[j] < a->data[i])
				smaller_count++;
			j++;
		}
		new_arr[i] = smaller_count;
		i++;
	}
	free(a->data);
	a->data = new_arr;
	return (1);
}

void	log_operation(t_environment *env, char *op_name)
{
	int	operation_length;

	operation_length = 0;
	env->operation_counter++;
	if (env->print_mode)
	{
		while (op_name[operation_length])
			operation_length++;
		write(1, op_name, operation_length);
		write(1, "\n", 1);
	}
}
