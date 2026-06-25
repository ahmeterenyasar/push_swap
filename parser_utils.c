/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:50:43 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:50:54 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	process_digits(const char **s, long *res)
{
	while (is_digit(**s))
	{
		if (*res > 214748364 || (*res == 214748364 && (**s - '0') > 8))
			return (0);
		*res = *res * 10 + (**s - '0');
		(*s)++;
	}
	if (**s != '\0' && !is_space(**s))
		return (0);
	return (1);
}

long	ft_strict_atol(const char **s, int *er_mg)
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
	if (!is_digit(**s) || !process_digits(s, &res))
	{
		*er_mg = 1;
		return (0);
	}
	return (res * result_sign);
}
