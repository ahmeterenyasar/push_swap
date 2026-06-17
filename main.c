
#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	stack_init(5);
	int capacity = 5;

	if (argc < 2)
		return (0);
	capacity = get_total_capacity(argc, argv);
	if (capacity <= 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	a = stack_init(capacity);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	if (!parser(a, argc, argv))
	{
		write(2, "Error\n", 6);
		stack_free(a);
		return (1);
	}
	
	printf("Mr.BrkyKapasite: %d\n", a->capacity);
	for (int i = 0; i < a->size; i++)
		printf("[%d] -> %d\n", i, a->data[i]);


	// şimdi mükerrerlik kontrolü yapacağız ingilizce öğretmeni olduğunu idda edenler için duplicate check diyebililiriz.
	

	return (0);
}