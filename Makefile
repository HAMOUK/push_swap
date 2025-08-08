NAME = push_swap

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c \
  ft_parsing.c \
  ft_aatoi.c \
  ft_operation1.c \
  ft_operation2.c \
  ft_operation3.c \
  ft_silent_operation1.c \
  ft_silent_operation2.c \
  ft_utils_listes.c \
  ft_utils_sort.c \
  ft_utils_stack.c \
  ft_utils_chunk.c \
  ft_utils.c \
  ft_algoritme.c \

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(MAKE) loading
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --silent

clean:
	@echo "🗑️ Removing object files from push_swap..."
	@rm -f $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR) --silent

fclean: clean
	@echo "🧺 Full clean: removing binary and libft archive..."
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent

re: fclean all

.PHONY: all clean fclean re

loading:
	@echo "✅ Compilation terminée avec succès !"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@