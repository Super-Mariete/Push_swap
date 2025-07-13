#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	free_split(char **split)
{
	int	i = 0;

	if (!split)
		return;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}


long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}

char *join_all_arguments(int argc, char **argv)
{
    char *joined;
    char *tmp;
    int i;

    joined = ft_strdup(argv[1]);
    if (!joined)
        return NULL;

    i = 2;
    while (i < argc)
    {
        tmp = ft_strjoin(joined, " ");
        free(joined);
        joined = ft_strjoin(tmp, argv[i]);
        free(tmp);
        if (!joined)
            return NULL;
        i++;
    }
    return joined;
}
