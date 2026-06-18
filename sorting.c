#include "push_swap.h"

int is_sorted(t_stack *a)
{
    int i;
    i = 0;
    while (i < a->size - 1)
    {
        if (a->data[i] > a->data[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void to_top(t_environment *env, int wanted_number)
{
	int current_location;
	int total_items;
	int inverse_distance;

	current_location = 0;
	
	while (env->a->data[current_location] != wanted_number)
	{
		current_location++;
	}
		
	total_items = env->a->size;
	
	if (current_location <= (total_items / 2))
	{
		while (current_location-- > 0)
			ra(env);
	}
    else
	{
		inverse_distance = total_items - current_location;
		while (inverse_distance-- > 0)
			rra(env);
	}
}

void sort_three(t_environment *env)
{
	int *numbers;

	numbers = env->a->data;
	if (numbers[0] > numbers[1] && numbers[1] < numbers[2] && numbers[2] > numbers[0])
		sa(env);
	else if (numbers[0] > numbers[1] && numbers[1] > numbers[2])
	{
		sa(env);
		rra(env);
	}
	else if (numbers[0] > numbers[1] && numbers[2] < numbers[0])
		ra(env);
	else if (numbers[0] < numbers[1] && numbers[1] > numbers[2] && numbers[2] > numbers[0])
	{
		sa(env);
		ra(env);
	}
	else if (numbers[0] < numbers[1] && numbers[2] < numbers[0])
		rra(env);
}


void small_sort(t_environment *env)
{
	int b_stackine_gonderilecek_eleman_sayisi;
	int su_an_aranan_kucuk_deger;
	if (env->a->size == 2)
	{
		if (env->a->data[0] > env->a->data[1])
			sa(env);
		return ;
	}
	b_stackine_gonderilecek_eleman_sayisi = env->a->size - 3;
	su_an_aranan_kucuk_deger = 0;
	while (su_an_aranan_kucuk_deger < b_stackine_gonderilecek_eleman_sayisi)
	{
		to_top(env, su_an_aranan_kucuk_deger);
		pb(env);
		su_an_aranan_kucuk_deger++;
	}
	sort_three(env);
	while (env->b->size > 0)
	{
		pa(env);
	}
}

int get_max_bits(int n)
{
	int	bits;
	int	max_val;
 
	bits = 0;
	max_val = n - 1;
	while (max_val > 0)
	{
		max_val >>= 1;
		bits++;
	}
	return (bits);
}

void radix_sort(t_environment *env)
{
    int i;
    int bit;

    if (is_sorted(env->a))
    {
        return ;
    }
    if (env->a->size <= 5)
    {
        return (small_sort(env));
    }

    int size;
    int total_bits;
    total_bits = get_max_bits(env->a->size);
	bit = 0;
	while (bit < total_bits)
	{
		size = env->a->size;
		i = 0;
		while (i < size)
		{
			if (((env->a->data[0] >> bit) & 1) == 0)
				pb(env);
			else
				ra(env);
			i++;
		}
		while (env->b->size > 0)
			pa(env);
		bit++;
	}
}
