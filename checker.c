/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:47:29 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 14:39:32 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		sa(*stack_a, 0);
	else if (compstr("sb\n", move))
		sb(*stack_b, 0);
	else if (compstr("ss\n", move))
		ss(*stack_a, *stack_b, 0);
	else if (compstr("rr\n", move))
		rr(stack_a, stack_b, 0);
	else if (compstr("ra\n", move))
		ra(stack_a, 0);
	else if (compstr("rb\n", move))
		rb(stack_b, 0);
	else if (compstr("pa\n", move))
		pa(stack_a, stack_b, 0);
	else if (compstr("pb\n", move))
		pb(stack_a, stack_b, 0);
	else if (compstr("rrr\n", move))
		rrr(stack_a, stack_b, 0);
	else if (compstr("rrb\n", move))
		rrb(stack_b, 0);
	else if (compstr("rra\n", move))
		rra(stack_a, 0);
}

int	read_and_sort(t_stack **stack_a, t_stack **stack_b)
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
			write(2, "Error\n", 6);
			return (1);
		}
		free(move);
		move = get_next_line(0);
	}
	get_next_line(-1);
	return (0);
}

void	initialize_stacks(int ac, char **av, t_stack **stack_a,
		t_stack **stack_b, char ***numbers, int *size)
{
	*stack_b = NULL;
	*size = count_args(&av[1]);
	*numbers = (char **)malloc(sizeof(char *) * (*size + 1));
	if (!*numbers)
		exit(1);
	(*numbers)[0] = NULL;
	proccess_argments(&av[1], *numbers);
	if (ac < 2)
		exit(1);
	if (!check_args(*numbers, *size))
		exit_error(*numbers, 1);
	if (!check_duplicates(*numbers, *size))
		exit_error(*numbers, 1);
	*stack_a = fill_stack_a(*size, *numbers);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;
	int		size;
	int		err;

	initialize_stacks(ac, av, &stack_a, &stack_b, &numbers, &size);
	err = read_and_sort(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b && !err)
		write(1, "OK\n", 3);
	else if ((!is_sorted(stack_a) || stack_b) && !err)
		write(1, "KO\n", 3);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	free_all(numbers);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	char	**numbers;
// 	int		size;
// 	int		err;

// 	stack_b = NULL;
// 	size = count_args(&av[1]);
// 	numbers = (char **)malloc(sizeof(char *) * (size + 1));
// 	if (!numbers)
// 		return (1);
// 	numbers[0] = NULL;
// 	proccess_argments(&av[1], numbers);
// 	if (ac < 2)
// 		return (1);
// 	if (!check_args(numbers, size))
// 		exit_error(numbers, 1);
// 	if (!check_duplicates(numbers, size))
// 		exit_error(numbers, 1);
// 	stack_a = fill_stack_a(size, numbers);
// 	err = read_and_sort(&stack_a, &stack_b);
// 	if (is_sorted(stack_a) && !stack_b && !err)
// 		write(1, "OK\n", 3);
// 	else if ((!is_sorted(stack_a) || stack_b) && !err)
// 		write(1, "KO\n", 3);
// 	stack_clear(&stack_a);
// 	stack_clear(&stack_b);
// 	free_all(numbers);
// 	return (0);
// }
