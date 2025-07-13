/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funtions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:42:59 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/12 00:48:15 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_lista **a)
{
	t_lista	*first;
	t_lista	*last;

	if (!*a || !(*a)->next)
		return;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;

	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_putstr("ra\n");
}

void	rb(t_lista **b)
{
	t_lista	*first;
	t_lista	*last;

	if (!*b || !(*b)->next)
		return;
	first = *b;
	*b = (*b)->next;
	first->next = NULL;

	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_putstr("rb\n");
}

void	rr(t_lista **a, t_lista **b)
{
	ra(a);
	rb(b);
	ft_putstr("rr\n");
}
