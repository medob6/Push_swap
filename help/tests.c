#include "push_swap.h"

void	test_push(void (*f)(t_stack **, t_stack **), t_stack **Stack_a,
		t_stack **Stack_b)
{
	printf("before push\n\n");
	printf("Stack a : \n\n");
	print_stack(*Stack_a);
	printf("Stack b : \n\n");
	print_stack(*Stack_b);
	f(Stack_a, Stack_b);
	printf("\nafter push\n\n");
	printf("Stack a : \n\n");
	print_stack(*Stack_a);
	printf("Stack b : \n\n");
	print_stack(*Stack_b);
	printf("\n ============================ \n\n");
}

void	test_rotat(void (*f)(t_stack **), t_stack **Stack_a, int n)
{
	if (n == 1)
		printf("before rotation\n\n");
	else if (n == 2)
		printf("before revers rotation\n\n");
	print_stack(*Stack_a);
	f(Stack_a);
	if (n == 1)
		printf("after rotation\n\n");
	else if (n == 2)
		printf("after revers rotation\n");
	print_stack(*Stack_a);
	printf("\n ============================ \n\n");
}

void	test_rr_rrr(void (*f)(t_stack **, t_stack **), t_stack **Stack_a,
		t_stack **stack_b, int n)
{
	if (n == 1)
		printf("before rr\n\n");
	else if (n == 2)
		printf("before rrr\n\n");
	printf("Stack a : \n\n");
	print_stack(*Stack_a);
	printf("Stack b : \n\n");
	print_stack(*stack_b);
	f(Stack_a, stack_b);
	if (n == 1)
		printf("after rr\n\n");
	else if (n == 2)
		printf("after revers rrr\n");
	printf("Stack a : \n\n");
	print_stack(*Stack_a);
	printf("Stack b : \n\n");
	print_stack(*stack_b);
	printf("\n ============================ \n\n");
}
void	test_swap(void (*f)(t_stack *), t_stack *Stack_a)
{
	printf("before swap\n\n");
	print_stack(Stack_a);
	f(Stack_a);
	printf("after swap\n\n");
	print_stack(Stack_a);
	printf("\n ============================ \n\n");
}

void	test_ss(void (*f)(t_stack *, t_stack *), t_stack *stack_a,
		t_stack *stack_b)
{
	printf("before ss\n\n");
	printf("Stack a : \n\n");
	print_stack(stack_a);
	printf("Stack b : \n\n");
	print_stack(stack_b);
	f(stack_a, stack_b);
	printf("after ss\n\n");
	printf("Stack a : \n\n");
	print_stack(stack_a);
	printf("Stack b : \n\n");
	printf("\n ============================ \n\n");
}

void	test_sort(void (*f)(t_stack **, t_stack **, int), t_stack **Stack_a,
		t_stack **Stack_b, int size)
{
	printf("before sort\n\n");
	print_stack(*Stack_a);
	f(Stack_a, Stack_b, size);
	printf("after sort\n\n");
	print_stack(*Stack_a);
	printf("\n ============================ \n\n");
}

void	test_all_actions(t_stack **stack_a, t_stack **stack_b)
{
	test_push(pb, stack_a, stack_b);
	test_push(pa, stack_a, stack_b);
	printf("\n");
	test_rr_rrr(rr, stack_a, stack_b, 1);
	printf("\n");
	test_rr_rrr(rrr, stack_a, stack_b, 2);
	printf("\n");
	test_ss(ss, *stack_a, *stack_b);
	test_rotat(rb, stack_b, 1);
	printf("\n");
	test_swap(sa, *stack_a);
	printf("\n");
	test_swap(sb, *stack_b);
	printf("\n");
	test_rotat(ra, stack_a, 1);
	printf("\n");
	test_rotat(rra, stack_a, 2);
	printf("\n");
	test_rotat(rrb, stack_b, 2);
}