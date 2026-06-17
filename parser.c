#include "push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static long	ft_strict_atol(const char **s, int *er_mg)
{}

int get_total_capacity(int argc, char **argv)
{
	int			i = 1;
	int			counter = 0;
	char	*ptr;

	while (i < argc)
	{
		ptr = argv[i];
		while (*ptr)
		{
			while (is_space(*ptr))
				ptr++;
			if (*ptr == '\0')
				break;
			if (*ptr == '+' || *ptr == '-')
				ptr++;
			if (!is_digit(*ptr))
				return (-1);
			while (is_digit(*ptr))
				ptr++;
			counter++;
		}
		i++;
	}
	return (counter);
}

/*
normalde split kullanırdım ama saygıdeğer şizofren kurulun
 bunu intihal olarak hayal edebileceğini düşünerekten double pointer
 gibi pointer ilerleterek kontrol edeceğim. anladınız mı?
*/

int parser(t_stack *a, int argc, char **argv)
{
    /*
    commit mesajlarını da ben yazıyorum he haberiniz olsun
    */
   // anlamayan bazı insanlar olur diye açıklayayım index 1 argv[1]i inceleyerek başlayalım diye kapito?
   int i = 1;
   int err = 0;
   long value; // long yapmamın sebebi integer'dan büyük girilse de kontrol edeceğim ama programa işlenmeyecek tabii ki aslında unsigned long long da yapılabilir
   char *ptr;

   while (i < argc)
   {
        ptr = argv[i];
        while (*ptr)
        {
            while (is_space(*ptr))
                ptr++;
            if (*ptr == '\0')
            {
                break;
            }
            value = ft_strict_atol(&ptr, &err);
            if (err)
            {
                return (0);
            }
            a->data[a->size++] = value;
        }
        i++;
   }
   return 1;
}