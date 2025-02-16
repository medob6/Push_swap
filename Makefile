CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I .
SRC = push_swap.c push_swap_utils.c sort_utils2.c stack_a_b_utils.c \
      stack_b_utils.c parser.c push_swap_utils2.c sort_array.c \
      sort_utils.c stack_a_utils.c utils/get_next_line.c \
      utils/get_next_line_utils.c utils/libft_utils2.c \
      utils/libft_utils.c utils/split.c
SRC_BONUS = checker.c utils/libft_utils2.c utils/libft_utils.c \
            utils/get_next_line.c utils/get_next_line_utils.c \
            stack_a_utils.c stack_a_b_utils.c stack_b_utils.c parser.c \
            utils/split.c push_swap_utils.c sort_array.c push_swap_utils2.c
NAME = push_swap
BONUS = checker
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_BONUS) -o $(BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME) $(BONUS)

re: fclean all
