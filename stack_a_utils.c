/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:45:04 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 09:45:05 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = temp;
}

void	sa(t_stack *stack_a)
{
	if (!stack_a || !stack_a->next)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	ra(t_stack **stack_a)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rra(t_stack **stack_a)
{
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	revrotate(stack_a);
	write(1, "rra\n", 4);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;

	if (!stack_a || !stack_b || !*stack_b)
		return ;
	head = *stack_b;
	(*stack_b) = head->next;
	if (head->next)
		head->next->previos = NULL;
	if (*stack_a)
		(*stack_a)->previos = head;
	head->next = *stack_a;
	*stack_a = head;
	write(1, "pa\n", 3);
}
