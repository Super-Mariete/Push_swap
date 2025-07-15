/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:56:20 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/15 13:43:59 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_values(t_lista *stack)
{
    while (stack)
    {
        printf("%ld\n", stack->data);
        stack = stack->next;
    }
}

void print_indexes(t_lista *stack)
{
    while (stack)
    {
        printf("%d\n", stack->index);
        stack = stack->next;
    }
}


void index_list(t_lista *stack)
{
    t_lista *current;
    t_lista *compare;

    current = stack;
    while (current)
    {
        int index = 0;
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

void	use_funtions(t_lista **a, t_lista **b)
{
	pb(a, b);
	pb(a, b);
}

int	main(int argc, char **argv)
{
	t_lista	*stack_a;
	t_lista	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	control_error(argc, argv);
	create_list(argc, argv, &stack_a);
//	print_values(stack_a);
	index_list(stack_a);
//	ft_putchar ('\n');
//	print_indexes(stack_a);
//	use_funtions(&stack_a, &stack_b);
//	print_values(stack_a);
//	ft_putchar('\n');
	sort_stack(&stack_a, &stack_b);
//	print_values(stack_a);
	return (0);
}
