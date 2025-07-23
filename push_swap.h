/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-ped <made-ped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:01:10 by made-ped          #+#    #+#             */
/*   Updated: 2025/07/23 23:55:25 by made-ped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

# define ERROR "ERROR\n"
# define ERROR_DOBLE "ERROR\n"
# define ERROR_VACIO "ERROR\n"

typedef struct s_lista
{
	struct s_lista	*next;
	long			data;
	int				index;
}	t_lista;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	control_error(int argc, char **argv);
void	check_order(char **tokens);
void	free_split(char **split);
void	create_list(int argc, char **argv, t_lista **lista);
void	add_nodo(t_lista **begin, char *data);
void	ft_lista_foreach(t_lista *begin, void (*f)(long*));
void	sa(t_lista **a);
void	sb(t_lista **b);
void	ss(t_lista **a, t_lista **b);
void	pa(t_lista **a, t_lista **b);
void	pb(t_lista **a, t_lista **b);
void	ra(t_lista **a);
void	rb(t_lista **b);
void	rr(t_lista **a, t_lista **b);
void	rra(t_lista **a);
void	rrb(t_lista **b);
void	rrr(t_lista **a, t_lista **b);
void	sort_stack(t_lista **a, t_lista **b);
void	radix_sort(t_lista **a, t_lista **b);
void	sort_small_stack(t_lista **a, t_lista **b);
void	sort_five(t_lista **stack_a, t_lista **stack_b);
void	sort_three(t_lista **stack);
void	free_list(t_lista *stack);
t_lista	*create_nodo(char *str);
t_lista	*found_last(t_lista **begin);
long	ft_atol(const char *str);
char	*join_all_arguments(int argc, char **argv);
int		get_max_bits(t_lista *stack);
int		ft_lstsize_lista(t_lista *lst);

#endif
