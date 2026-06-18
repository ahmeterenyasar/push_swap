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
    int i, j;

    int *new_arr = malloc(sizeof(int) * a->size);
    if (!new_arr)
        return ;
    int smaller_count;

        i = 0;
    	while (i < a->size)
    	{
    		smaller_count = 0;
    		j = 0;
    		while (j < a->size)
    		{
    			/*
                kendisinden daha küçük kaç sayı var sayıcaz ve ona göre indexlicez
                bu daha faerkllı bir manntık kapiş
                */ 
    			if (a->data[j] < a->data[i])
    				smaller_count++;
    			j++;
    		}
    		// bulduğumuz sayıyı o elemanın yeni indeksi yapacaz
    		new_arr[i] = smaller_count;
    		i++;
    	}
        free(a->data);
        a->data = new_arr;
    
    
}
