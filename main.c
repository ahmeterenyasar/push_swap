#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int	is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
        || c == '\f' || c == '\r');
}

static int	is_valid_number_token(const char *s)
{
    int	i;

    if (!s || s[0] == '\0')
        return (0);
    i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (s[i] == '\0')
        return (0);
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

static int	append_value(int **arr, int *count, int value)
{
    int	*new_arr;

    new_arr = (int *)realloc(*arr, sizeof(int) * (*count + 1));
    if (!new_arr)
        return (0);
    *arr = new_arr;
    (*arr)[*count] = value;
    (*count)++;
    return (1);
}

static int	parse_token(const char *start, int len, int *out)
{
    char	buf[32];
    char	*end;
    long	value;
    int		i;

    if (len <= 0 || len >= (int)sizeof(buf))
        return (0);
    i = 0;
    while (i < len)
    {
        buf[i] = start[i];
        i++;
    }
    buf[i] = '\0';
    if (!is_valid_number_token(buf))
        return (0);
    value = strtol(buf, &end, 10);
    if (*end != '\0' || value < INT_MIN || value > INT_MAX)
        return (0);
    *out = (int)value;
    return (1);
}

static int	parse_argument_string(const char *arg, int **arr, int *count)
{
    int	i;
    int	start;
    int	len;
    int	value;

    i = 0;
    while (arg[i])
    {
        while (arg[i] && is_space(arg[i]))
            i++;
        start = i;
        while (arg[i] && !is_space(arg[i]))
            i++;
        len = i - start;
        if (len > 0)
        {
            if (!parse_token(arg + start, len, &value))
                return (0);
            if (!append_value(arr, count, value))
                return (0);
        }
    }
    return (1);
}

static int	parse_inputs(int argc, char **argv, int **arr, int *count)
{
    int	i;

    i = 1;
    while (i < argc)
    {
        if (!parse_argument_string(argv[i], arr, count))
            return (0);
        i++;
    }
    return (1);
}

int	main(int argc, char **argv)
{
    int	*numbers;
    int	count;
    int	i;

    if (argc < 2)
        return (0);
    numbers = NULL;
    count = 0;
    if (!parse_inputs(argc, argv, &numbers, &count) || count == 0)
    {
        free(numbers);
        printf("Error\n");
        return (1);
    }
    printf("Toplam %d sayi parse edildi:\n", count);
    i = 0;
    while (i < count)
    {
        printf("%d\n", numbers[i]);
        i++;
    }
    free(numbers);
    return (0);
}
