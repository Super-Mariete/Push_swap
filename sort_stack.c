/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:00:58 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/16 22:33:23 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_lista(t_lista *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	get_max_bits(t_lista *stack)
{
	int	max;
	int	bits;

	max = ft_lstsize_lista(stack) - 1;
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

void	radix_sort(t_lista **a, t_lista **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = ft_lstsize_lista(*a);
	max = get_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

void	sort_stack(t_lista **a, t_lista **b)
{
	int	size;

	size = ft_lstsize_lista(*a);
	if (size <= 5)
		sort_small_stack(a, b);
	else
		radix_sort(a, b);
}
