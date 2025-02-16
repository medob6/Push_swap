CC = cc -I .
CFLAGS = -g
# -Wall -Werror -Wextra 
SRC = push_swap.c push_swap_utils.c  sort_utils2.c  stack_a_b_utils.c  stack_b_utils.c parser.c   push_swap_utils2.c  sort_array.c  sort_utils.c   stack_a_utils.c utils/get_next_line.c  utils/get_next_line_utils.c  utils/libft_utils2.c  utils/libft_utils.c  utils/split.c
SRC_BONUS = checker.c utils/libft_utils2.c utils/libft_utils.c utils/get_next_line.c utils/get_next_line_utils.c stack_a_utils.c stack_a_b_utils.c stack_b_utils.c parser.c utils/split.c push_swap_utils.c sort_array.c push_swap_utils2.c
NAME= push_swap
BONUS= checker

RM = rm -f

all:$(NAME)

$(NAME): 
	@$(CC) $(SRC) $(CFLAGS) -o $(NAME) 

bonus:$(BONUS)

$(BONUS):
	@$(CC) $(SRC_BONUS) $(CFLAGS) -o $(BONUS)


re:fclean all

fclean:
	@rm -f $(NAME) $(BONUS)