#include "push_swap.h"

t_stack	*stack_init(int capacity)
{
    t_stack	*stack;
	stack = (t_stack *)malloc(sizeof(t_stack));
    stack->capacity = capacity;
	stack->size = 0;
	stack->data = (int *)malloc(sizeof(int) * capacity);
    if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

void	stack_free(t_stack *stack)
{
    
}