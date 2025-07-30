/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 12:46:42 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/24 00:24:41 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
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

int	validate_token(const char *token)
{
	long	num;

	if (!is_valid_number(token))
	{
		return (1);
	}
	num = ft_atol(token);
	if (num > INT_MAX || num < INT_MIN)
	{
		return (1);
	}
	return (0);
}

void	check_duplicates(char **tokens)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

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
				ft_putstr_fd(ERROR, 2);
				free_split(tokens);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

static void	handle_arguments(int argc, char **argv, char ***tokens)
{
	char	*all_args;

	if (argc < 2 || !argv[1] || !*argv[1])
	{
		exit(0);
	}
	if (argc == 2)
		all_args = ft_strdup(argv[1]);
	else
		all_args = join_all_arguments(argc, argv);
	*tokens = ft_split(all_args, ' ');
	free(all_args);
	if (!(*tokens)[1])
	{
		free_split(*tokens);
		exit(0);
	}
	if (!*(*tokens))
	{
		free_split(*tokens);
		exit(0);
	}
}

void	control_error(int argc, char **argv)
{
	char	**tokens;
	int		i;
	int		check;

	handle_arguments(argc, argv, &tokens);
	i = 0;
	while (tokens[i])
	{
		check = validate_token(tokens[i]);
		if (check == 1)
		{
			ft_putstr_fd(ERROR, 2);
			free_split(tokens);
			exit(1);
		}
		i++;
	}
	check_duplicates(tokens);
	check_order(tokens);
	free_split(tokens);
}
