/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:32:15 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:47:09 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static long	ft_strict_atol(const char **s, int *er_mg)
{
	long	res;
	int		result_sign;

	res = 0;
	result_sign = 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			result_sign = -1;
		(*s)++;
	}
	if (!is_digit(**s))
	{
		*er_mg = 1;
		return (0);
	}
	while (is_digit(**s))
	{
		if (res > 214748364 || (res == 214748364 && (**s - '0') > 8))
		{
			*er_mg = 1;
			return (0);
		}
		res = res * 10 + (**s - '0');
		(*s)++;
	}
	if (**s != '\0' && !is_space(**s))
	{
		*er_mg = 1;
		return (0);
	}
	return (res * result_sign);
}

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
