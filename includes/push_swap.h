/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:07:32 by mbraets           #+#    #+#             */
/*   Updated: 2022/03/29 15:19:13 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	long long		content;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				index;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_list			*result;
}					t_stacks;

t_stack	*ft_stacknew(long long content);
void	ft_stackadd_back(t_stack **alst, t_stack *new);
void	ft_stackclear(t_stack **lst);
int		ft_stacklenght(t_stack *lst);
t_stack	*stack_pop(t_stack **stack);
void	stack_push(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stackbeforelast(t_stack *lst);
int		sorted(t_stack *lst);
int		indexof(t_stack *stack, t_stack *tofind);
void	push_stack_top_a(t_stacks *stacks, t_stack *topush);
t_stack	*getmin(t_stack *stack);

// UTILS

int		ft_strisdigit(char *s);
void	error(t_stacks *stacks);
int		find_duplicate_stack(t_stack *stack);
void	ft_putendl(void *s);
void	set_index(t_stack *stack);
int		check_integer(char **argv);

// Instruction

void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);

// Algo

void	number_3(t_stacks *stacks);
void	number_4(t_stacks *stacks);
void	number_5(t_stacks *stacks);
void	index_sort(t_stacks *stacks, int chunk);
void	radix_sort(t_stacks *stacks);
#endif