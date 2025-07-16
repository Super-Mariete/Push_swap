/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_funtions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:47:23 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/16 21:28:02 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_lista **a)
{
	t_lista	*prev;
	t_lista	*last;

	if (!*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	ft_putstr("rra\n");
}

void	rrb(t_lista **b)
{
	t_lista	*prev;
	t_lista	*last;

	if (!*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	ft_putstr("rrb\n");
}

void	rrr(t_lista **a, t_lista **b)
{
	rra(a);
	rrb(b);
	ft_putstr("rrr\n");
}
