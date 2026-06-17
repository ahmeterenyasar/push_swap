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

typedef struct s_environment
{
	t_stack *a;
	t_stack *b;
	// bunların da adını değişek aq stack dedik diye intihal yerim belki idk
	int operation_counter;
	int print_mode; // -> tam olarak burası yazdırmamızı sağlayacak okkey kafamda öyle kurdum yani
} t_env;

typedef struct s_stack
{
	int	*data;
	int	size;
	int	capacity;
}	t_stack;

t_stack	*stack_init(int capacity);
void	stack_free(t_stack *stack);

// Parsing
int		is_valid_format(char *str);
long	ft_atol(const char *str);
int		get_total_capacity(int argc,char **argv);
int		parser(t_stack *a, int argc, char **argv);


#endif