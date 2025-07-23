/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:11:23 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/23 23:30:24 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_lista **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

void	sort_four(t_lista **stack_a, t_lista **stack_b)
{
	while (ft_lstsize_lista(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_lista **stack_a, t_lista **stack_b)
{
	while (ft_lstsize_lista(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	if (*stack_b && (*stack_b)->next && (*stack_b)->index
		< (*stack_b)->next->index)
		sb(stack_b);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	sort_small_stack(t_lista **a, t_lista **b)
{
	int	size;

	size = ft_lstsize_lista(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
