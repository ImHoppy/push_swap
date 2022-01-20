/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:07:01 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/20 06:11:23 by mbraets          ###   ########.fr       */
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
	// len++;
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
