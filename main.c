/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:56:20 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/13 14:56:02 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_foreach(t_lista *begin, void (*f)(void *))
{
	t_lista *current = begin;
	while (current != NULL)
	{
		f(current->data);
		current = current->next;
	}
}

void	print_list(void *c)
{
	printf("%ld\n", *(long *)c);
}

int	main(int argc, char **argv)
{
	t_lista	*stack_a;
//	t_lista	*stack_b;

	stack_a = NULL;
//	stack_b = NULL;
	control_error(argc, argv);
	create_list(argc, argv, &stack_a);
	ft_list_foreach(stack_a, print_list);
	return (0);
}
