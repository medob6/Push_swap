/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:44:57 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 09:59:18 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	tail = head;
	while (tail->next)
		tail = tail->next;
	*stack = head->next;
	head->next->previos = NULL;
	head->next = NULL;
	tail->next = head;
	head->previos = tail;
}

void	rb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	sb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->next)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*tail;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	tail = *stack_b;
	revrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;

	if (!stack_a || !stack_b || !*stack_a)
		return ;
	head = *stack_a;
	*stack_a = head->next;
	if (head->next)
		head->next->previos = NULL;
	head->next = (*stack_b);
	if (*stack_b)
		(*stack_b)->previos = head;
	(*stack_b) = head;
	write(1, "pb\n", 3);
}
