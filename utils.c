#include "push_swap.h"

int mükerrer_check(t_stack *a)
{
    int i, j;

    i = 0;
    while (i < a->size)
    {
        j = i + 1;
        while (j < a->size)
        {
            if (a->data[i] == a->data[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void convert_to_indexed(t_stack *a)
{
    
}
