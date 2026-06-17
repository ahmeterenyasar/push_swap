
#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	stack_init(5);
	int capacity = 5;

	if (argc < 2)
		return (0);
	// burda hata varsa -1 dönelim error atarız
	capacity = get_total_capacity(argc, argv);
	printf("%d", capacity);


	return (0);
}