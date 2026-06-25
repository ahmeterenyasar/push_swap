/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:26:02 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/25 15:54:42 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*data;
	int		size;
	int		capacity;
}			t_stack;

typedef struct s_environment
{
	t_stack	*a;
	t_stack	*b;
	int		operation_counter;
	int		print_mode;
}			t_environment;

t_stack		*stack_init(int capacity);
void		stack_free(t_stack *stack);

int			get_total_capacity(int argc, char **argv);
int			parser(t_stack *a, int argc, char **argv);
int			has_no_copies(t_stack *a);
int			convert_to_indexed(t_stack *a);

void		sa(t_environment *env);
void		sb(t_environment *env);
void		ss(t_environment *env);
void		pa(t_environment *env);
void		pb(t_environment *env);
void		ra(t_environment *env);
void		rra(t_environment *env);
void		rb(t_environment *env);
void		rrb(t_environment *env);
void		rr(t_environment *env);
void		rrr(t_environment *env);

void		to_top(t_environment *env, int wanted_number);
void		radix_sort(t_environment *env);
int			get_max_bits(int n);

int			is_space(char c);
int			is_digit(char c);
long		ft_strict_atol(const char **s, int *er_mg);

int			is_sorted(t_stack *a);
void		log_operation(t_environment *env, char *op_name);
int			convert_to_indexed(t_stack *a);

#endif