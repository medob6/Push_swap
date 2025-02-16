/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_b_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:45:07 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 09:58:49 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_b || !stack_b->next || !stack_a || !stack_a->next)
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((!*stack_b || !(*stack_b)->next) || (!*stack_a || !(*stack_a)->next))
		return ;
	revrotate(stack_a);
	revrotate(stack_b);
	write(1, "rrr\n", 4);
}

void	revrotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = lst_last(head);
	if (last->previos)
		last->previos->next = NULL;
	first->previos = last;
	last->next = first;
	last->previos = NULL;
	*head = last;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((!*stack_b || !(*stack_b)->next) || (!*stack_a || !(*stack_a)->next))
		return ;
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
