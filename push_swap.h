#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>



typedef struct s_stack
{
	int	*data;
	int	size;
	int	capacity;
}	t_stack;

t_stack	*stack_init(int capacity);
void	stack_free(t_stack *stack);

// Parsing
int		is_valid_format(char *str);
long	ft_atol(const char *str);
int		get_total_capacity(int argc,char **argv);
int parser(t_stack *a, int argc, char **argv);


#endif