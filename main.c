
#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_environment env;
	int capacity;

	if (argc < 2)
		return (0);

	capacity = get_total_capacity(argc, argv);
	if (capacity <= 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	env.a = stack_init(capacity);
	env.b = stack_init(capacity);
	env.operation_counter = 0;
	env.print_mode = 1;

	if (!parser(env.a, argc, argv))
	{
		write(2, "Error\n", 6);
		stack_free(env.a);
		stack_free(env.b);
		return (1);
	}

	if (!mükerrer_check(env.a))
	{
		write(2, "Error\n", 6);
		stack_free(env.a);
		stack_free(env.b);
		return (1);
	}

	stack_free(env.a);
	stack_free(env.b);

	return (0);
}