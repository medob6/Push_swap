/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:47:29 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 13:30:21 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// utils/libft_utils2.c get_next_line.c get_next_line_utils.c  stack_a_b utils .. parse.c  split.c push_swap_utils.c sort_array.c parse.c push_swap_utils2.c
int	move_valid(char *s)
{
	if (compstr("sa\n", s) || compstr("sb\n", s) || compstr("ss\n", s)
		|| compstr("rr\n", s) || compstr("ra\n", s) || compstr("rb\n", s)
		|| compstr("pa\n", s) || compstr("pb\n", s) || compstr("rrr\n", s)
		|| compstr("rrb\n", s) || compstr("rra\n", s))
		return (1);
	return (0);
}

void	do_move(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (compstr("sa\n", move))
		sa(*stack_a);
	else if (compstr("sb\n", move))
		sb(*stack_b);
	else if (compstr("ss\n", move))
		ss(*stack_a, *stack_b);
	else if (compstr("rr\n", move))
		rr(stack_a, stack_b);
	else if (compstr("ra\n", move))
		ra(stack_a);
	else if (compstr("rb\n", move))
		rb(stack_b);
	else if (compstr("pa\n", move))
		pa(stack_a, stack_b);
	else if (compstr("pb\n", move))
		pb(stack_a, stack_b);
	else if (compstr("rrr\n", move))
		rrr(stack_a, stack_b);
	else if (compstr("rrb\n", move))
		rrb(stack_b);
	else if (compstr("rra\n", move))
		rra(stack_a);
}

void	read_and_sort(t_stack **stack_a, t_stack **stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (move_valid(move))
			do_move(stack_a, stack_b, move);
		else
		{
			free(move);
			write(2, "Error\n", 7);
			return ;
		}
		free(move);
		move = get_next_line(0);
	}
	get_next_line(-1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;
	int		size;

	stack_b = NULL;
	size = count_args(&av[1]);
	numbers = (char **)malloc(sizeof(char *) * (size + 1));
	if (!numbers)
		return (1);
	numbers[0] = NULL;
	proccess_argments(&av[1], numbers);
	if (ac < 2)
		return (1);
	if (!check_args(numbers, size))
		exit_error(numbers, 1);
	if (!check_duplicates(numbers, size))
		exit_error(numbers, 1);
	stack_a = fill_stack_a(size, numbers);
	read_and_sort(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	free_all(numbers);
	return (0);
}
