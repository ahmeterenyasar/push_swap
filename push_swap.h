#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


/*
burada çok güzel bir çakallık yapacağım yeni evaluation pagede
live coding kısmında bizden yanlış hatırlamıyorsam operasyonları değil
kaç adet yapıldığını yazdırmamızı istiyormuş akran öğrenmesiyle öğrendim bu bilgiyi.
bende bunun için bir üst wrapper struct'ı koyacağım yani bütün bunlar ayrı bir pencerede
izleniyormuş gibi düşünebilirsiniz
*/


typedef struct s_stack
{
	int	*data;
	int	size;
	int	capacity;
}	t_stack;

typedef struct s_environment
{
	t_stack *a;
	t_stack *b;
	int operation_counter;
	int print_mode;
} t_environment;


t_stack	*stack_init(int capacity);
void	stack_free(t_stack *stack);

// Parsing
int		get_total_capacity(int argc,char **argv);
int		parser(t_stack *a, int argc, char **argv);
int mükerrer_check(t_stack *a);
void convert_to_indexed(t_stack *a);




#endif