/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:32:15 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/23 18:32:16 by ayasar           ###   ########.fr       */
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

int	get_total_capacity(int argc, char **argv)
{
	int		i;
	int		counter;
	char	*ptr;

	i = 1;
	counter = 0;
	while (i < argc)
	{
		ptr = argv[i];
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
		i++;
	}
	return (counter);
}

int	parser(t_stack *a, int argc, char **argv)
{
	int			i;
	int			err;
	long		value;
	const char	*ptr;

	i = 1;
	err = 0;
	while (i < argc)
	{
		ptr = argv[i];
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
		i++;
	}
	return (1);
}
