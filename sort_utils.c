/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:44:50 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 10:37:20 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int nbr, t_stack *stack)
{
	int	index;
	int	temp;

	index = 0;
	temp = stack->nbr;
	while (stack->next)
	{
		stack = stack->next;
		if (temp == nbr)
			return (index);
		temp = stack->nbr;
		index++;
	}
	if (temp == nbr)
		return (index);
	return (index);
}

int	smalln_pos(t_stack *stack)
{
	int		temp;
	t_stack	*head;

	head = stack;
	temp = stack->nbr;
	while (stack->next)
	{
		stack = stack->next;
		if (temp > stack->nbr)
			temp = stack->nbr;
	}
	return (get_index(temp, head));
}

void	push_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	i = smalln_pos(*stack_a);
	if (i > size / 2)
	{
		i = size - smalln_pos(*stack_a);
		while (i--)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (i--)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	push_best(t_stack **stack_a, t_stack **stack_b, int size, int pos)
{
	int	i;

	i = pos;
	if (i >= size / 2)
	{
		i = size - pos;
		while (i--)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (i--)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	push_n_small_nbr(int curr_stk_size, t_stack **stack_a,
		t_stack **stack_b, int n)
{

	while (n--)
	{
		push_small(stack_a, stack_b, curr_stk_size);
		curr_stk_size--;
	}
}
