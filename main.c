#include <stdio.h>
#include "push_swap.h"

void print_stacks(t_environment *env, const char *msg)
{
    printf("\n=====================================\n");
    printf("  %s\n", msg);
    printf("=====================================\n");

    // STACK A
    printf("--- STACK A (Boyut: %d) ---\n", env->a->size);
    if (env->a->size == 0)
        printf("[Bos]\n");
    for (int i = 0; i < env->a->size; i++)
        printf("[%d] -> %d\n", i, env->a->data[i]);

    printf("\n");

    // STACK B
    printf("--- STACK B (Boyut: %d) ---\n", env->b->size);
    if (env->b->size == 0)
        printf("[Bos]\n");
    for (int i = 0; i < env->b->size; i++)
        printf("[%d] -> %d\n", i, env->b->data[i]);
    
    printf("=====================================\n\n");
}

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

    convert_to_indexed(env.a);

    // print_stacks(&env, "OPERASYONLARDAN ONCE");

    // printf("--- Test Operasyonlari Basliyor ---\n");
    
    // sa(&env); 
    // rra(&env);
    // pb(&env);
    // pb(&env);
    // sb(&env);

	// printf("\n--- Test: Degerini En Uste Cikar ---\n");
    
    // to_top(&env, 0);

    // print_stacks(&env, "OPERASYONLARDAN SONRA");


	// ... [convert_to_indexed(env.a) sonrasi] ...

    printf("--- Islemlerden ONCE Stack A ---\n");
    for (int i = 0; i < env.a->size; i++)
        printf("[%d] -> %d\n", i, env.a->data[i]);

    printf("\nDegerini En Uste Cikar\n");
    
    to_top(&env, 0);

    printf("\n--- Islemlerden SONRA Stack A ---\n");
    for (int i = 0; i < env.a->size; i++)
        printf("[%d] -> %d\n", i, env.a->data[i]);


    stack_free(env.a);
    stack_free(env.b);

    return (0);
}