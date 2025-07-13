/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:46:42 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/13 14:45:38 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	validate_token(const char *token)
{
	long num;

	if (!is_valid_number(token))
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(1);
	}
	num = ft_atol(token);
	if (num > INT_MAX || num < INT_MIN)
	{
		ft_putstr_fd(ERROR_LIMIT, 2);
		exit(1);
	}
}

void	check_duplicates(char **tokens)
{
	int		i, j;
	long	num_i, num_j;

	i = 0;
	while (tokens[i])
	{
		num_i = ft_atol(tokens[i]);
		j = i + 1;
		while (tokens[j])
		{
			num_j = ft_atol(tokens[j]);
			if (num_i == num_j)
			{
				ft_putstr_fd(ERROR_DOBLE, 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void control_error(int argc, char **argv)
{
    char    *all_args;
    char    **tokens;
    int     i;

    if (argc < 2 || !argv[1] || !*argv[1])
        exit(0);

    if (argc == 2)
        all_args = ft_strdup(argv[1]);
    else
        all_args = join_all_arguments(argc, argv);
    tokens = ft_split(all_args, ' ');
    free(all_args);
    if (!tokens[1])
    {
		ft_putstr_fd(ERROR_1ARGC, 2);
		exit(0);
    }
    if (!*tokens)
    {
        ft_putstr_fd(ERROR_VACIO, 2);
        free_split(tokens);
        exit(1);
    }
    i = 0;
    while (tokens[i])
    {
        validate_token(tokens[i]);
        i++;
    }

    check_duplicates(tokens);
    free_split(tokens);
}
