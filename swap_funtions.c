/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funtions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:26:35 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/12 00:30:58 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	sa(t_lista **a)
{
	t_lista	*tmp;

	if (!*a || !(*a)->next)
		return;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	ft_putstr("sa\n");
}

void	sb(t_lista **b)
{
	t_lista	*tmp;

	if (!*b || !(*b)->next)
		return;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	ft_putstr("sb\n");
}

void	ss(t_lista **a, t_lista **b)
{
	sa(a);
	sb(b);
	ft_putstr("ss\n");
}
