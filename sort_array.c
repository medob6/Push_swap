/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:46:44 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 10:36:19 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	proccess_argments(char **unprc_args, char **result)
{
	int	i;

	i = 0;
	while (unprc_args[i])
	{
		appened_numbers(result, unprc_args[i]);
		i++;
	}
}

void	put_to_array(int *array, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a->next)
	{
		array[i] = stack_a->nbr;
		stack_a = stack_a->next;
		i++;
	}
	array[i] = stack_a->nbr;
}

int	partition(int *arr, int start, int end)
{
	int	pivot;
	int	pi;
	int	i;

	pi = start;
	i = start;
	pivot = arr[end];
	while (i < end)
	{
		if (arr[i] <= pivot)
		{
			fswap(&arr[i], &arr[pi]);
			pi = pi + 1;
		}
		i++;
	}
	fswap(&arr[pi], &arr[end]);
	return (pi);
}

void	quick_sort(int *array, int start, int end)
{
	int	pindex;

	if (start >= end)
		return ;
	pindex = partition(array, start, end);
	quick_sort(array, start, pindex - 1);
	quick_sort(array, pindex + 1, end);
}

void	qsort_array(int *array, int size)
{
	quick_sort(array, 0, size - 1);
}
