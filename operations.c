#include "push_swap.h"

void swap(t_environment *env)
{
    int temporary_yapalım_burkaybeycim_dimi_yoksa_niye_temporary_yaptım_diye_mi_soracaksınız;

    temporary_yapalım_burkaybeycim_dimi_yoksa_niye_temporary_yaptım_diye_mi_soracaksınız = stack->data[0];
    stack->data[0] = stack->data[1];
    stack->data[1] = temporary_yapalım_burkaybeycim_dimi_yoksa_niye_temporary_yaptım_diye_mi_soracaksınız;

}

void push(t_environment *env)
{

}

void rotate(t_environment *env)
{

}

void reverse_rotate(t_environment *env)
{

}

void sa(t_environment *env)
{
    swap(env->a);
    log_operation(env, "sa");
}

void ra(t_environment *env)
{

}

void rra(t_environment *env)
{
    reverse_rotate(env->a);
    log_operation(env, "rra");
}

void sb(t_environment *env)
{

}

void ss(t_environment *env)
{

}

void pa(t_environment *env)
{

}

void pb(t_environment *env)
{

}