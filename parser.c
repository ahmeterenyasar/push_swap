/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:51:27 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:52:26 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_numbers_in_str(char *ptr)
{
	int	counter;

	counter = 0;
	while (*ptr)
	{
		while (is_space(*ptr))
			ptr++;
		if (*ptr == '\0')
			break ;
		if (*ptr == '+' || *ptr == '-')
			ptr++;
		if (!is_digit(*ptr))
			return (-1);
		while (is_digit(*ptr))
			ptr++;
		counter++;
	}
	return (counter);
}

int	get_total_capacity(int argc, char **argv)
{
	int	i;
	int	counter;
	int	str_count;

	i = 1;
	counter = 0;
	while (i < argc)
	{
		str_count = count_numbers_in_str(argv[i]);
		if (str_count == -1)
			return (-1);
		counter += str_count;
		i++;
	}
	return (counter);
}

static int	parse_string_to_stack(t_stack *a, const char *ptr)
{
	long	value;
	int		err;

	err = 0;
	while (*ptr)
	{
		while (is_space(*ptr))
			ptr++;
		if (*ptr == '\0')
			break ;
		value = ft_strict_atol(&ptr, &err);
		if (err || value > 2147483647 || value < -2147483648)
			return (0);
		a->data[a->size++] = (int)value;
	}
	return (1);
}

int	parser(t_stack *a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_string_to_stack(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
