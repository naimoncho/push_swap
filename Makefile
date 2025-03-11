# Makefile

NAME = push_swap

LIBFT_DIR = libft
INCLUDES_DIR = includes

SRC = main.c find_prep.c stack_a-b.c stack_b-a.c alg_stack.c ft_split_ps.c order.c stack_in.c error.c ft_calloc_ps.c \
      push.c swap.c rever_rotate.c rotate.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_MOVEMENTS) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re