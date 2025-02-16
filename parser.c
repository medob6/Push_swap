/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:47:21 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 14:04:48 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] == '\0')
		return (0);
	if ((nbr[0] == '-' || nbr[0] == '+') && nbr[1] != '\0')
		i = 1;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!check_number(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(char **nums, int length)
{
	int	n;
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		n = ft_atoi(nums[i], nums);
		j = 0;
		while (nums[j])
		{
			if (j != i && n == ft_atoi(nums[j], nums))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_args(char **unprc_args)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (unprc_args[i])
	{
		counter += count_words(unprc_args[i], ' ');
		i++;
	}
	return (counter);
}

void	appened_numbers(char **prc_args, char *subarg)
{
	int		i;
	int		j;
	char	**sbsbargs;

	sbsbargs = ft_split(subarg, ' ');
	i = 0;
	j = 0;
	while (prc_args[i])
		i++;
	if (!sbsbargs[j])
	{
		free_all(sbsbargs);
		exit_error(prc_args, 1);
	}
	while (sbsbargs[j])
	{
		prc_args[i] = ft_strdup(sbsbargs[j]);
		i++;
		j++;
	}
	prc_args[i] = NULL;
	free_all(sbsbargs);
}
