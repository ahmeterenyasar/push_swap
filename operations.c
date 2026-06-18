#include "push_swap.h"

void log_operation(t_environment *env, char *op_name)
{
    int operation_length;
    operation_length = 0;
    env->operation_counter++;
    if (env->print_mode)
    {
        while(op_name[operation_length])
            operation_length++;
        write(1, op_name, operation_length);
        write(1, "\n", 1);
    }
}

void swap(t_stack *stack)
{
    int transient;

    if (stack->size < 2)
        return ;

    transient = stack->data[0];
    stack->data[0] = stack->data[1];
    stack->data[1] = transient;
}

void push(t_stack *dest, t_stack *src)
{
    int shift_idx;
    int popped_top;
    if (src->size == 0)
        return ;
    popped_top = src->data[0];
    shift_idx = 0;
    while (shift_idx < src->size - 1)
    {
        src->data[shift_idx] = src->data[shift_idx + 1];
        shift_idx++;
    }
    src->size--;
    shift_idx = dest->size;
    while (shift_idx > 0)
    {
        dest->data[shift_idx] = dest->data[shift_idx - 1];
        shift_idx--;
    }

    dest->data[0] = popped_top;
    dest->size++;
}

void rotate(t_stack *stack)
{
    int i;
    int x;
    
    x = stack->data[0];

    i = 0;
    while (i < stack->size - 1)
    {
        stack->data[i] = stack->data[i + 1];
        i++;
    }
    stack->data[stack->size - 1] = x;
}

void reverse_rotate(t_stack *stack)
{
    int i;
    int x;

    x = stack->data[stack->size - 1];

    i = stack->size - 1;
    while (i > 0)
    {
        stack->data[i] = stack->data[i - 1];
        i--;
    }
    stack->data[0] = x;
}

void sa(t_environment *env)
{
    swap(env->a);
    log_operation(env, "sa");
}

void sb(t_environment *env)
{
    swap(env->b);
    log_operation(env, "sb");
}

void ss(t_environment *env)
{
    swap(env->a);
    swap(env->b);
    log_operation(env, "ss");
}

void pa(t_environment *env)
{
    push(env->a, env->b);
    log_operation(env, "pa");
}

void pb(t_environment *env)
{
    push(env->b, env->a);
    log_operation(env, "pb");
}

void ra(t_environment *env)
{
    rotate(env->a);
    log_operation(env, "ra");
}

void rra(t_environment *env)
{
    reverse_rotate(env->a);
    log_operation(env, "rra");
}

void rb(t_environment *env)
{
    rotate(env->b);
    log_operation(env, "rb");
}

void rrb(t_environment *env)
{
    reverse_rotate(env->b);
    log_operation(env, "rrb");
}

void rr(t_environment *env)
{
    rotate(env->a);
    rotate(env->b);
    log_operation(env, "rr");
}

void rrr(t_environment *env)
{
    reverse_rotate(env->a);
    reverse_rotate(env->b);
    log_operation(env, "rrr");
}