#include <limits.h>
#include <stdio.h>
#include <stdlib.h>



int	main(int argc, char **argv)
{
    int *a;
    if (argc < 2)
        return 0;

    a = malloc(sizeof(int) * argc);
    int i = 0;
    while (i < argc)
    {
        a[i] = atoi(argv[i]);
        i++;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }
    
    
	return (0);
}
