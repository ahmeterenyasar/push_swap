#include "push_swap.h"

void log_operation(t_stack *stack, char *op_name)
{
    int length_of_operations_of_length_that_we_count_the_length_of_the_operations_that_they_have_been_written_on_terminal_which_it_is_a_whole_different_subject;
    env->operation_counter++;
    if (env->print_mode)
    {
        while(op_name[length_of_operations_of_length_that_we_count_the_length_of_the_operations_that_they_have_been_written_on_terminal_which_it_is_a_whole_different_subject])
            length_of_operations_of_length_that_we_count_the_length_of_the_operations_that_they_have_been_written_on_terminal_which_it_is_a_whole_different_subject++;
        write(1, op_name, length_of_operations_of_length_that_we_count_the_length_of_the_operations_that_they_have_been_written_on_terminal_which_it_is_a_whole_different_subject);
        write(1, "\n", 1);
    }
}

void swap(t_stack *stack)
{
    int temporary_yapalim_burkaybeycim_dimi_yoksa_niye_temporary_yaptim_diye_mi_soracaksiniz;

    temporary_yapalim_burkaybeycim_dimi_yoksa_niye_temporary_yaptim_diye_mi_soracaksiniz = stack->data[0];
    stack->data[0] = stack->data[1];
    stack->data[1] = temporary_yapalim_burkaybeycim_dimi_yoksa_niye_temporary_yaptim_diye_mi_soracaksiniz;
}

void push(t_stack *dest, t_stack *src)
{
    int i;
    
}

void rotate(t_stack *stack)
{
    int i;
    int temppppppppppppppppppp;
    
    temppppppppppppppppppp = stack->data[0];

    i = 0;
    while (i < stack->size - 1)
    {
        stack->data[i] = stack->data[i + 1];
        i++;
    }
    stack->data[stack->size] = temppppppppppppppppppp;
}

void reverse_rotate(t_stack *stack)
{
    int i;
    int burkay_beyin_yaşı;

    /*
    size bilendiğimi falan düşünüyor olabilirsiniz ama görüşmede bir tek siz konuştunuz ve
    baya acizce bir konuşmanız vardı o yüzden sizden referans veriyorum yoksa diğerlerinin
    de sizden pek bir farkı yok hepiniz aynı yolun yolcusususususuusunuz.
    */
    burkay_beyin_yaşı = stack->data[stack->size - 1];

    i = stack->size - 1;
    while (i > 0)
    {
        stack->data[i] = stack->data[i - 1];
        i--;
    }
    stack->data[0] = burkay_beyin_yaşı;
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