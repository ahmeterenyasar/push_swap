
#include <stdio.h>
#include "push_swap.h"

int main(void)
{
	t_stack	*a;
	a = stack_init(5);
	if (!a)
	{
		printf("Malloc patladi!\n");
		return (1);
	}

	printf("Stack olusturuldu.\n");
	printf("Kapasite: %d\n", a->capacity);
	printf("Mevcut Eleman Sayisi: %d\n", a->size);

	stack_free(a);
	printf("Stack bellekten silindi. Temiz is!\n");

	return (0);
}