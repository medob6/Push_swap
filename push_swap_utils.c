/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:47:17 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 09:54:29 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_a(int size, char **numbers)
{
	int		i;
	t_stack	*stack;
	t_stack	*temp;

	stack = ft_lstnew(ft_atoi(numbers[0], numbers));
	stack->previos = NULL;
	temp = stack;
	i = 0;
	while (++i < size)
	{
		temp->next = ft_lstnew(ft_atoi(numbers[i], numbers));
		temp->next->previos = temp;
		temp = temp->next;
	}
	temp->next = NULL;
	return (stack);
}

void	stack_clear(t_stack **lst)
{
	t_stack	*lst_node;
	t_stack	*temp_node;

	if (!lst || !*lst)
		return ;
	lst_node = *lst;
	while (lst_node)
	{
		temp_node = lst_node;
		lst_node = lst_node->next;
		free(temp_node);
	}
	*lst = NULL;
}

int	get_chunk_size(int size)
{
	int	n;

	if (size <= 8)
		n = 5;
	else if (size > 8 && size <= 15)
		n = 3;
	else if (size > 15 && size <= 36)
		n = 4;
	else if (size > 36 && size <= 100)
		n = 12;
	else if (size > 100 && size <= 500)
		n = 30;
	else
		n = 15;
	return (n);
}

int	next_nrange(t_stack *stack, int range)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = stack;
	while (head)
	{
		if (head->index <= range)
		{
			return (i);
		}
		i++;
		head = head->next;
	}
	return (i);
}

int	is_sorted(t_stack *stack_a)
{
	int	temp;

	if (!stack_a)
		return (1);
	temp = stack_a->nbr;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (temp > stack_a->nbr)
			return (0);
		temp = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}
