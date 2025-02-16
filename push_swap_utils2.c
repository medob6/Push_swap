/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:47:11 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 10:34:26 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(char **nums, int code)
{
	write(2, "Error\n", 6);
	free_all(nums);
	exit(code);
}

int	find_nbr(t_stack *stack, int index)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = stack;
	while (i < index)
	{
		temp = stack->next;
		i++;
	}
	return (temp->nbr);
}

void	sort3num(t_stack **stack_a)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->nbr > (*stack_a)->next->next->nbr)
	{
		ra(stack_a);
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(*stack_a);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr)
	{
		sa(*stack_a);
		if ((*stack_a)->nbr > (*stack_a)->next->next->nbr)
			ra(stack_a);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->next->nbr)
	{
		rra(stack_a);
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(*stack_a);
	}
	else if ((*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
	{
		rra(stack_a);
		sa(*stack_a);
	}
}
