/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:25:56 by ayasar            #+#    #+#             */
/*   Updated: 2026/06/23 18:25:57 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int has_no_copies(t_stack *a)
{
    int i;
    int j;

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
    int i;
    int j;
    int smaller_count;
    int *new_arr;

    new_arr = malloc(sizeof(int) * a->size);
    if (!new_arr)
    {
        write(2, "Error\n", 6);
        exit(1); 
    }
    i = 0;
    while (i < a->size)
    {
        smaller_count = 0;
        j = 0;
        while (j < a->size)
        {
            if (a->data[j] < a->data[i])
                smaller_count++;
            j++;
        }
        new_arr[i] = smaller_count;
        i++;
    }
    free(a->data);
    a->data = new_arr;
}
