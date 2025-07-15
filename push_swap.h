#ifndef	PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "Libft/libft.h"

#define ERROR_MESSAGE "Los parametros no son correctos primo\n"
#define ERROR_LIMIT "Te pasate de número bro\n"
#define ERROR_DOBLE "El número está duplicado chaval\n"
#define ERROR_VACIO "El string esta vacio man\n"
#define ERROR_1ARGC "Solo hay un número menda\n"

typedef struct s_lista
{
	struct s_lista	*next;
	long		data;
	int		index;
}	t_lista;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	control_error(int argc, char **argv);
void    free_split(char **split);
void	create_list(int	argc, char **argv, t_lista **lista);
void	add_nodo(t_lista **begin, char *data);
void	ft_lista_foreach(t_lista *begin, void(*f)(long*));
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
void    sort_stack(t_lista **a, t_lista **b);
void    radix_sort(t_lista **a, t_lista **b);
void    sort_small_stack(t_lista **a, t_lista **b);
void	sort_five(t_lista **stack_a, t_lista **stack_b);
void	sort_three(t_lista **stack);
void	free_list(t_lista *stack);
t_lista	*create_nodo(char *str);
t_lista	*found_last(t_lista **begin);
long    ft_atol(const char *str);
char    *join_all_arguments(int argc, char **argv);
int     get_max_bits(t_lista *stack);
int	ft_lstsize_lista(t_lista *lst);

#endif
