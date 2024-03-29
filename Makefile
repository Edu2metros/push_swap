PUSH_SWAP_NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g3 -O3
INCLUDES = -I ./include/

SRC_DIR = src
OBJ_DIR = objs

PUSH_SWAP_SRC = main.c reverse_rotate_moves.c push.c free.c check_args.c sort.c utils.c rotate_moves.c swap_moves.c sort_three.c radix.c
PUSH_SWAP_OBJ = $(addprefix $(OBJ_DIR)/, $(PUSH_SWAP_SRC:%.c=%.o))

all: libft $(PUSH_SWAP_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) libft
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ)
	$(CC) $(FLAGS) $(PUSH_SWAP_OBJ) ./include/libft/libft.a -o $(PUSH_SWAP_NAME)

libft:
	@make -C ./include/libft

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ./include/libft

fclean: clean
	@rm -f $(PUSH_SWAP_NAME)
	@make fclean -C ./include/libft
	@echo "$(PUSH_SWAP_NAME) removed."

re: fclean all

.PHONY: all clean fclean re libft
