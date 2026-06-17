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
{
    long res = 0;
    int result_sign = 1;

    //önce işareti yakalayacğaım tamam mı anladık mı bkaın hata yapmıyorum ama şuan hata yapılacak bir durum yok valla kopya falan değil ilaçlarınızı alın
    if (**s == '-' || **s == '+')
    {
        if (**s == '-')
            result_sign = -1;
        (*s)++;
    }
    
    // işaretten sonra sayı gelmesi lazım diye düşünüyorum eğer sayı değilse errrrror
    if (!is_digit(**s))
    {
        *er_mg = 1;
        return (0);
    }

    while (is_digit(**s))
    {
        res = res * 10 + (**s - '0');
        (*s)++;
    }
    
    if (**s != '\0' && !is_space(**s))
    {
        *er_mg = 1;
        return (0);
    }
    return res * result_sign;
}

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
   int i = 1;
   int err = 0;
   long value;
   const char *ptr;

   while (i < argc)
   {
        ptr = argv[i];
        while (*ptr)
        {
            while (is_space(*ptr))
                ptr++;
            if (*ptr == '\0')
                break;
            value = ft_strict_atol(&ptr, &err);
            if (err || value > 2147483647 || value < -2147483648)
                return (0);
            a->data[a->size++] = (int)value;
        }
        i++;
   }
   return 1;
}
