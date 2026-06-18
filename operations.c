#include "push_swap.h"

void log_operation(t_environment *env, char *op_name)
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

void push(t_environment *env)
{

}

void rotate(t_environment *env)
{
    int i;
    int temppppppppppppppppppp;
    
    temp = env
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