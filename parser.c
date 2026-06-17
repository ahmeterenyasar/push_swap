#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}