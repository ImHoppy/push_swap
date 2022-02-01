/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:14:40 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/01 16:58:01 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	insertion_sort(t_stacks *stacks, int chunk)
{
	(void) chunk;
	while (stacks->a != NULL)
	{
		push_stack_top_a(stacks, getmin(stacks->a));
		push_b(stacks);
	}
	while (stacks->b != NULL)
		push_a(stacks);
}

int	sumStack(t_stack *stack)
{
	t_stack	*head;
	int		sum;

	head = stack;
	sum = 0;
	while (head != NULL)
	{
		sum += head->content;
		head = head->next;
	}
	return (sum);
}


void	reverse_or_rotate_a(t_stacks *stacks, t_stack *topush)
{
	int		len;
	int		middle;
	void	(*ptr)(t_stacks*);

	len = ft_stacklenght(stacks->a);
	middle = indexof(stacks->a, topush);
	if (middle < len / 2)
		ptr = &rotate_a;
	else
		ptr = &reverse_rotate_a;
	ptr(stacks);
}

void	reverse_or_rotate_b(t_stacks *stacks, t_stack *topush)
{
	int		len;
	int		middle;
	void	(*ptr)(t_stacks*);

	len = ft_stacklenght(stacks->b);
	middle = indexof(stacks->b, topush);
	if (middle < len / 2)
		ptr = &rotate_b;
	else
		ptr = &reverse_rotate_b;
	ptr(stacks);
}

void	push_average_a(t_stacks *stacks, t_stack *topush, int average)
{
	while (stacks->a != topush)
	{
		if (stacks->a->content <= average)
			push_b(stacks);
		else
			rotate_a(stacks);
	}
}

void	split_stack_a(t_stacks *stacks)
{
	int		size;
	int		average;
	t_stack	*min;
	
	size = ft_stacklenght(stacks->a);
	average = sumStack(stacks->a) / size;
	min = getmin(stacks->a);
	while (min->content <= average)
	{
		if (stacks->a->content <= average)
			push_b(stacks);
		else
			push_average_a(stacks, min, average);
		min = getmin(stacks->a);
	}
}
#include <stdio.h>
int	calc_distance(t_stack *stack, t_stack *min, t_stack *max)
{
	int	min_index;
	int	max_index;
	int min_res;
	int max_res;
	int	size;
	int ret;

	size = ft_stacklenght(stack);
	min_index = indexof(stack, min);
	max_index = indexof(stack, max);
	min_res = 	min_index  ;
	max_res = 	max_index  ;
	
	ret = min_res < max_res;
	return (ret);
}

int	push_max_min(t_stacks *stacks)
{
	t_stack	*min;
	t_stack	*max;
	int		maxaction;

	maxaction = 0;
	while (stacks->b != NULL)
	{
		min = getmin(stacks->b);
		max = getmax(stacks->b);
		if (stacks->b == max)
		{
			push_a(stacks);
			maxaction++;
		}
		if (stacks->b == min)
		{
			push_a(stacks);
			rotate_a(stacks);
		}

		if (calc_distance(stacks->b, min, max) == 0)
			reverse_or_rotate_b(stacks, min);
		else
			reverse_or_rotate_b(stacks, max);
		// rotate_b(stacks);
	}
	return (maxaction);
}

void	quarter_sort(t_stacks *stacks)
{

	split_stack_a(stacks);
	int remaning = ft_stacklenght(stacks->a);
	int max = push_max_min(stacks);
	while (max-- != 0)
	{
		rotate_a(stacks);
	}
	while (remaning-- != 0)
	{
		push_b(stacks);
	}
	max = push_max_min(stacks);

	while (max-- != 0)
	{
		rotate_a(stacks);
	}
	// split_stack_a(stacks);
	// split_stack_b(stacks);
}

// First attempt of creating my own sort

// void	insertion_sort(t_stacks *stacks, int chunk)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	t_stack	*last[2];

// 	// if (chunk == 0)
// 	if (sorted(stacks->a))
// 		return;
// 	a = stacks->a;
// 	b = stacks->b;
// 	last[0] =	ft_stacklast(a);
// 	last[1] =	ft_stacklast(b);
// 	while (a->next != NULL && !sorted(stacks->a))
// 	// while (chunk != 0)
// 	{
// 		if (a->content > last[0]->content)
// 		{
// 			rotate_a(stacks);
// 			last[0] = last[0]->next;
// 		}
// 		else if (a->content > a->next->content)
// 		{
// 			swap_a(stacks);
// 			// push_b(stacks);
// 		}
// 		else
// 		{
// 			push_b(stacks);
// 			if (stacks->b->next != NULL && stacks->b->content < stacks->b->next->content)
// 			{
// 				swap_b(stacks);
// 			}
// 			// if ()
// 		}
// 		if (last[1] != NULL && stacks->b->content < last[1]->content)
// 		{
// 			rotate_b(stacks);
// 			last[1] = ft_stacklast(b);
// 		}
// 		a = stacks->a;
// 	}

	
// 	b = stacks->b;
// 	last[1] = ft_stacklast(b);
// 	while (b != NULL && b->next != NULL )
// 	{
// 		if (last[1] != NULL && b->content > last[1]->content)
// 		{
// 			rotate_b(stacks);
// 			last[1] = last[1]->next;
// 		}
// 		else if (b->content > b->next->content)
// 		{
// 			swap_b(stacks);
// 			// push_b(stacks);
// 		}
// 		else if (stacks->a->content < stacks->b->content)
// 			push_a(stacks);
// 		else
// 		{
// 			push_a(stacks);
// 			if (stacks->a->next != NULL && stacks->a->content > stacks->a->next->content)
// 				swap_a(stacks);
// 		}
// 		b = stacks->b;
// 	}
// 	chunk--;
// 	if (stacks->b != NULL)
// 		push_a(stacks);
// 	insertion_sort(stacks, chunk);
// }