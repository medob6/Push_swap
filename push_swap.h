/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:46:49 by mbousset          #+#    #+#             */
/*   Updated: 2025/02/16 10:36:35 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/get_next_line.h"
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Stack structure
typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previos;
}					t_stack;

// Utility functions
int					ft_isdigit(int c);
int					ft_atoi(const char *str, char **numbers);
char				*ft_strdup(const char *s1);
char				**ft_split(const char *str, char c);
void				exit_error(char **nums, int code);
void				free_all(char **p);

// Stack initialization and management
t_stack				*ft_lstnew(int content);
t_stack				*fill_stack_a(int size, char **av);
void				stack_clear(t_stack **lst);

// Stack operations (individual stacks)
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);

// Stack operations (both stacks)
void				ss(t_stack *stack_a, t_stack *stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// Sorting and helper functions
void				qsort_array(int *array, int size);
void				push_back(t_stack **stack_a, t_stack **stack_b, int size);
void				revrotate(t_stack **stack);
void				swap(t_stack *stack);
void				rotate(t_stack **stack);
void				fswap(int *a, int *b);

// Argument processing
int					count_words(const char *str, char c);
int					count_args(char **unprc_args);
int					compstr(const char *s1, const char *s2);
int					check_duplicates(char **nums, int length);
int					check_args(char **numbers, int size);
void				proccess_argments(char **unprc_args, char **result);
void				appened_numbers(char **prc_args, char *subarg);

// Indexing and array operations
void				index_elements(t_stack **stack, int *arr, int size);
int					get_index(int nbr, t_stack *stack);
void				put_to_array(int *array, t_stack *stack_a);
int					is_sorted(t_stack *stack_a);
int					get_chunk_size(int size);

// Sorting strategies
void				sort3num(t_stack **stack_a);
void				push_n_small_nbr(int curr_stk_size, t_stack **stack_a,
						t_stack **stack_b, int n);
void				push_n_big_nbr(int size, t_stack **stack_a,
						t_stack **stack_b);
int					next_nrange(t_stack *stack, int range);

// Helper function
t_stack				*lst_last(t_stack **lst);

#endif
