PUSH_SWAP_NAME = push_swap
CC = cc
 FLAGS = -g3
INCLUDES = -I ./libft/

OBJ_DIR = objs

PUSH_SWAP_SRC = main.c moves.c push.c free.c check_args.c sort.c
PUSH_SWAP_OBJ = $(addprefix $(OBJ_DIR)/, $(PUSH_SWAP_SRC:%.c=%.o))

C_SRC = main.c moves_stack_a.c moves_stack_b.c
C_OBJ = $(addprefix $(OBJ_DIR)/, $(C_SRC:%.c=%.o))

all: libft $(PUSH_SWAP_NAME)

$(PUSH_SWAP_OBJ): $(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) libft
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ)
	$(CC) $(FLAGS) $(PUSH_SWAP_OBJ) ./libft/libft.a -o $(PUSH_SWAP_NAME)

$(C_OBJ): $(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

libft:
	@make -C ./libft

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@rm -f $(PUSH_SWAP_NAME)
	@make fclean -C ./libft
	@echo "$(PUSH_SWAP_NAME) removed."

re: fclean all

.PHONY: all clean fclean re libft
