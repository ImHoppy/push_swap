/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:07:01 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/24 17:04:13 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_stackadd_front(t_stack **alst, t_stack *new)
{
	if (alst == NULL || new == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}

int	ft_stacklenght(t_stack *lst)
{
	int	len;

	len = 1;
	if (lst == NULL)
		return (0);
	lst = lst->next;
	if (lst != NULL)
		len += ft_stacklenght(lst);
	return (len);
}

void	ft_stackclear(t_stack **lst)
{
	t_stack	*list;
	t_stack	*old;

	list = *lst;
	while (list != NULL)
	{
		old = list->next;
		if (list != NULL)
		{
			// list->content = NULL;
			free(list);
		}
		list = old;
	}
	*lst = 0;
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack *stack_pop(t_stack **stack)
{
	t_stack	*popped;
	
	popped = *stack;
	(*stack) = (*stack)->next;
	return (popped);
}

void stack_push(t_stack **stack, t_stack *new)
{
	if (new == NULL)
		return ;
	if (stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}