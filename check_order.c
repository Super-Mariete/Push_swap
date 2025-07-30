/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:57:47 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/24 00:12:03 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_order(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] && tokens[i + 1])
	{
		if (ft_atol(tokens[i + 1]) < ft_atol(tokens[i]))
			return ;
		i++;
	}
	free_split(tokens);
	exit(0);
}
