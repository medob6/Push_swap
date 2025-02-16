/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:45:09 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 10:34:57 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_n_big_nbr(int size, t_stack **stack_a, t_stack **stack_b)
{
	while (size)
	{
		push_back(stack_a, stack_b, size);
		size--;
	}
}

int	big_n_pos(t_stack *stack)
{
	int		temp;
	t_stack	*head;

	head = stack;
	temp = stack->nbr;
	while (head->next)
	{
		head = head->next;
		if (temp < head->nbr)
			temp = head->nbr;
	}
	return (get_index(temp, stack));
}

void	push_back(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	i = big_n_pos(*stack_b);
	if (i > size / 2)
	{
		i = size - big_n_pos(*stack_b);
		while (i--)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		while (i--)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
}

int	check_range(int start, int end, int *arr, int nbr)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (arr[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

void	index_elements(t_stack **stack, int *arr, int size)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = *stack;
	while (head)
	{
		i = 0;
		while (i < size)
		{
			if (head->nbr == arr[i])
			{
				head->index = i;
				break ;
			}
			i++;
		}
		head = head->next;
	}
}
