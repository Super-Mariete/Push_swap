/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:46:48 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/16 22:00:11 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lista	*found_last(t_lista **begin)
{
	t_lista	*current;

	current = *begin;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_lista	*create_nodo(char *str)
{
	t_lista	*nodo;

	nodo = malloc(sizeof(t_lista));
	if (!nodo)
		return (NULL);
	nodo->data = atol(str);
	nodo->index = 0;
	nodo->next = NULL;
	return (nodo);
}

void	add_nodo(t_lista **begin, char *data)
{
	t_lista	*new;
	t_lista	*last;

	new = create_nodo(data);
	if (*begin == NULL)
	{
		*begin = new;
		return ;
	}
	last = found_last(begin);
	last->next = new;
}

void	create_list(int argc, char **argv, t_lista **begin)
{
	char	*all_args;
	char	**data;
	int		i;

	if (argc == 2)
		all_args = ft_strdup(argv[1]);
	else
		all_args = join_all_arguments(argc, argv);
	data = ft_split(all_args, ' ');
	free(all_args);
	if (!data)
		return ;
	i = 0;
	while (data[i])
	{
		add_nodo(begin, data[i]);
		i++;
	}
	free_split(data);
}
