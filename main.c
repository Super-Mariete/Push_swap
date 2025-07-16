/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:56:20 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/16 21:46:50 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_lista *stack)
{
	t_lista	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	index_list(t_lista *stack)
{
	t_lista	*current;
	t_lista	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->data > compare->data)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_lista	*stack_a;
	t_lista	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	control_error(argc, argv);
	create_list(argc, argv, &stack_a);
	index_list(stack_a);
	sort_stack(&stack_a, &stack_b);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
/*
void	print_values(t_lista *stack)
{
	while (stack)
	{
		printf("%ld\n", stack->data);
		stack = stack->next;
	}
}

void	print_indexes(t_lista *stack)
{
	while (stack)
	{
		printf("%d\n", stack->index);
		stack = stack->next;
	}
}
*/
