/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:46:57 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 13:18:52 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// now final check   DONE
// pars argment      DONE
// make mini algo for 3 numbers : DONE
// discase algo of sorting   : DONE
// make algo of sorting : IN PROGRES

// int	check_number(char *nbr)
// {
// 	int	i;

// 	i = 0;
// 	if (nbr[0] == '\0')
// 		return (0);
// 	if ((nbr[0] == '-' || nbr[0] == '+') && nbr[1] != '\0')
// 		i = 1;
// 	while (nbr[i])
// 	{
// 		if (!ft_isdigit(nbr[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
// int	check_args(char **numbers, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (!check_number(numbers[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	check_duplicates(char **nums, int length)
// {
// 	int	n;
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < length)
// 	{
// 		n = ft_atoi(nums[i], nums);
// 		j = 0;
// 		while (nums[j])
// 		{
// 			if (j != i && n == ft_atoi(nums[j], nums))
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// static int	count_words(const char *str, char c)
// {
// 	int	i;
// 	int	counter;
// 	int	in_word;

// 	i = 0;
// 	counter = 0;
// 	in_word = 0;
// 	while (str[i])
// 	{
// 		if ((str[i] != c) && !in_word)
// 		{
// 			in_word = 1;
// 			counter++;
// 		}
// 		else if (str[i] == c)
// 		{
// 			in_word = 0;
// 		}
// 		i++;
// 	}
// 	return (counter);
// }
// int	count_args(char **unprc_args)
// {
// 	int	counter;
// 	int	i;

// 	i = 0;
// 	counter = 0;
// 	while (unprc_args[i])
// 	{
// 		counter += count_words(unprc_args[i], ' ');
// 		i++;
// 	}
// 	return (counter);
// }

// void	appened_numbers(char **prc_args, char *subarg)
// {
// 	int		i;
// 	int		j;
// 	char	**sbsbargs;

// 	sbsbargs = ft_split(subarg, ' ');
// 	i = 0;
// 	j = 0;
// 	while (prc_args[i])
// 		i++;
// 	if (!sbsbargs[j])
// 	{
// 		free_all(sbsbargs);
// 		exit_error(prc_args, 1);
// 	}
// 	while (sbsbargs[j])
// 	{
// 		prc_args[i] = ft_strdup(sbsbargs[j]);
// 		i++;
// 		j++;
// 	}
// 	prc_args[i] = NULL;
// 	free_all(sbsbargs);
// }
// void	proccess_argments(char **unprc_args, char **result, int res_size)
// {
// 	int	i;

// 	i = 0;
// 	while (unprc_args[i])
// 	{
// 		appened_numbers(result, unprc_args[i]);
// 		i++;
// 	}
// }

// void	free_all(char **p)
// {
// 	int	i;

// 	i = 0;
// 	if (!p)
// 		return ;
// 	while (p[i])
// 	{
// 		free(p[i]);
// 		i++;
// 	}
// 	free(p);
// }
// void	exit_error(char **nums, int code)
// {
// 	write(2, "Error\n", 6);
// 	free_all(nums);
// 	exit(1);
// }

// int	find_nbr(t_stack *stack, int index)
// {
// 	int		i;
// 	t_stack	*temp;

// 	i = 1;
// 	temp = stack;
// 	while (i < index)
// 	{
// 		temp = stack->next;
// 		i++;
// 	}
// 	return (temp->nbr);
// }

// void	sort3num(t_stack **stack_a)
// {
// 	if ((*stack_a)->nbr > (*stack_a)->next->nbr
// 		&& (*stack_a)->nbr > (*stack_a)->next->next->nbr)
// 	{
// 		ra(stack_a);
// 		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
// 			sa(*stack_a);
// 	}
// 	else if ((*stack_a)->nbr > (*stack_a)->next->nbr)
// 	{
// 		sa(*stack_a);
// 		if ((*stack_a)->nbr > (*stack_a)->next->next->nbr)
// 			ra(stack_a);
// 	}
// 	else if ((*stack_a)->nbr > (*stack_a)->next->next->nbr)
// 	{
// 		rra(stack_a);
// 		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
// 			sa(*stack_a);
// 	}
// 	else if ((*stack_a)->next->nbr > (*stack_a)->next->next->nbr)
// 	{
// 		rra(stack_a);
// 		sa(*stack_a);
// 	}
// }

// int	get_index(int nbr, t_stack *stack)
// {
// 	int	index;
// 	int	temp;

// 	index = 0;
// 	temp = stack->nbr;
// 	while (stack->next)
// 	{
// 		stack = stack->next;
// 		if (temp == nbr)
// 			return (index);
// 		temp = stack->nbr;
// 		index++;
// 	}
// 	if (temp == nbr)
// 		return (index);
// 	return (index);
// }
// int	smalln_pos(t_stack *stack)
// {
// 	int		temp;
// 	t_stack	*head;

// 	head = stack;
// 	temp = stack->nbr;
// 	while (stack->next)
// 	{
// 		stack = stack->next;
// 		if (temp > stack->nbr)
// 			temp = stack->nbr;
// 	}
// 	return (get_index(temp, head));
// }

// void	push_small(t_stack **stack_a, t_stack **stack_b, int size)
// {
// 	int	i;

// 	i = smalln_pos(*stack_a);
// 	if (i > size / 2)
// 	{
// 		i = size - smalln_pos(*stack_a);
// 		while (i--)
// 			rra(stack_a);
// 		pb(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		while (i--)
// 			ra(stack_a);
// 		pb(stack_a, stack_b);
// 	}
// }

// void	push_best(t_stack **stack_a, t_stack **stack_b, int size, int pos)
// {
// 	int	i;

// 	i = pos;
// 	if (i >= size / 2)
// 	{
// 		i = size - pos;
// 		while (i--)
// 			rra(stack_a);
// 		pb(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		while (i--)
// 			ra(stack_a);
// 		pb(stack_a, stack_b);
// 	}
// }
// void	push_n_small_nbr(int curr_stk_size, t_stack **stack_a,
// 		t_stack **stack_b, int n)
// {
// 	int	i;

// 	while (n--)
// 	{
// 		push_small(stack_a, stack_b, curr_stk_size);
// 		curr_stk_size--;
// 	}
// }

// int	is_sorted(t_stack *stack_a)
// {
// 	int	temp;

// 	if (!stack_a)
// 		return (1);
// 	temp = stack_a->nbr;
// 	stack_a = stack_a->next;
// 	while (stack_a)
// 	{
// 		if (temp > stack_a->nbr)
// 			return (0);
// 		temp = stack_a->nbr;
// 		stack_a = stack_a->next;
// 	}
// 	return (1);
// }

// void	put_to_array(int *array, t_stack *stack_a)
// {
// 	int	i;

// 	i = 0;
// 	while (stack_a->next)
// 	{
// 		array[i] = stack_a->nbr;
// 		stack_a = stack_a->next;
// 		i++;
// 	}
// 	array[i] = stack_a->nbr;
// }

// void	fswap(int *a, int *b)
// {
// 	int	temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// int	partition(int *arr, int start, int end)
// {
// 	int	pivot;
// 	int	pi;
// 	int	i;

// 	pi = start;
// 	i = start;
// 	pivot = arr[end];
// 	while (i < end)
// 	{
// 		if (arr[i] <= pivot)
// 		{
// 			fswap(&arr[i], &arr[pi]);
// 			pi = pi + 1;
// 		}
// 		i++;
// 	}
// 	fswap(&arr[pi], &arr[end]);
// 	return (pi);
// }
// void	quick_sort(int *array, int start, int end)
// {
// 	int	pindex;

// 	if (start >= end)
// 		return ;
// 	pindex = partition(array, start, end);
// 	quick_sort(array, start, pindex - 1);
// 	quick_sort(array, pindex + 1, end);
// }

// void	qsort_array(int *array, int size)
// {
// 	quick_sort(array, 0, size - 1);
// }
////////////////////////////
// void	print_array(int *array, int size)
// {
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%d ", array[i]);
// 	}
// 	printf("\n");
// }
////////////////////////////
// int	get_chunk_size(int size)
// {
// 	int	n;

// 	if (size <= 8)
// 		n = 5;
// 	else if (size > 8 && size <= 15)
// 		n = 3;
// 	else if (size > 15 && size <= 36)
// 		n = 4;
// 	else if (size > 36 && size <= 100)
// 		n = 12;
// 	else if (size > 100 && size <= 500)
// 		n = 30;
// 	else
// 		n = 15;
// 	return (n);
// }

// void	push_n_big_nbr(int size, t_stack **stack_a, t_stack **stack_b)
// {
// 	int	i;

// 	while (size)
// 	{
// 		push_back(stack_a, stack_b, size);
// 		size--;
// 	}
// }
// int	big_n_pos(t_stack *stack)
// {
// 	int		temp;
// 	t_stack	*head;

// 	head = stack;
// 	temp = stack->nbr;
// 	while (head->next)
// 	{
// 		head = head->next;
// 		if (temp < head->nbr)
// 			temp = head->nbr;
// 	}
// 	return (get_index(temp, stack));
// }
// void	push_back(t_stack **stack_a, t_stack **stack_b, int size)
// {
// 	int	i;

// 	i = big_n_pos(*stack_b);
// 	if (i > size / 2)
// 	{
// 		i = size - big_n_pos(*stack_b);
// 		while (i--)
// 			rrb(stack_b);
// 		pa(stack_a, stack_b);
// 	}
// 	else
// 	{
// 		while (i--)
// 			rb(stack_b);
// 		pa(stack_a, stack_b);
// 	}
// }

// int	check_range(int start, int end, int *arr, int nbr)
// {
// 	int	i;

// 	i = start;
// 	while (i <= end)
// 	{
// 		if (arr[i] == nbr)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void	index_elements(t_stack **stack, int *arr, int size)
// {
// 	int		i;
// 	t_stack	*head;

// 	i = 0;
// 	head = *stack;
// 	while (head)
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			if (head->nbr == arr[i])
// 			{
// 				head->index = i;
// 				break ;
// 			}
// 			i++;
// 		}
// 		head = head->next;
// 	}
// }

// int	next_nrange(t_stack *stack, int range)
// {
// 	int		i;
// 	t_stack	*head;

// 	i = 0;
// 	head = stack;
// 	while (head)
// 	{
// 		if (head->index <= range)
// 		{
// 			return (i);
// 		}
// 		i++;
// 		head = head->next;
// 	}
// 	return (i);
// }

///////////////////////////////////////////////////
void	get_next_nrang(t_stack **stack_a, int size, int range)
{
	int	i;

	i = 0;
	i = next_nrange(*stack_a, range);
	if (i > size / 2)
	{
		i = size - next_nrange(*stack_a, range);
		while (i--)
			rra(stack_a);
	}
	else
	{
		while (i--)
			ra(stack_a);
	}
}

void	move_elements_to_b(t_stack **stack_a, t_stack **stack_b, int size,
		int range)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			get_next_nrang(stack_a, size - i, range + i);
	}
}

void	big_sort_algo(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	*elements;
	int	range;

	elements = (int *)malloc(sizeof(int) * (size + 1));
	if (!elements)
		return ;
	if (*stack_a && !*stack_b)
		put_to_array(elements, *stack_a);
	qsort_array(elements, size);
	range = get_chunk_size(size);
	index_elements(stack_a, elements, size);
	move_elements_to_b(stack_a, stack_b, size, range);
	push_n_big_nbr(size, stack_a, stack_b);
	free(elements);
}

void	main_sort_algo(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (is_sorted(*stack_a) && !(*stack_b))
		return ;
	if (stack_size == 2)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(*stack_a);
		return ;
	}
	else if (stack_size <= 5)
	{
		push_n_small_nbr(stack_size, stack_a, stack_b, stack_size - 3);
		sort3num(stack_a);
		while ((stack_size-- - 3))
			pa(stack_a, stack_b);
	}
	else
		big_sort_algo(stack_a, stack_b, stack_size);
}

// int	main(int ac, char **av)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	char	**numbers;
// 	int		size;

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
// 	main_sort_algo(&stack_a, &stack_b, size);
// 	stack_clear(&stack_a);
// 	stack_clear(&stack_b);
// 	free_all(numbers);
// 	return (0);
// }
