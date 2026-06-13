#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>



typedef struct s_stack
{
	int	*data;
	int	size;
	int	capacity;
}	t_stack;


#endif