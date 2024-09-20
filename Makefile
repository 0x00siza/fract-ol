
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = include/libft
MLX_PATH = include/minilibx

SRC_DIR = src
INCLUDE_DIR = -Iinclude

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = ${SRC_FILES:.c=.o}

LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -I$(MLX_PATH) -c -o $@ $<
	
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)


clean:
	@$(MAKE) clean -C $(LIBFT_PATH) 
	@$(MAKE) clean -C $(MLX_PATH) 
	@rm -f $(OBJ_FILES)



fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH) 
	@rm -f $(NAME)
	

re: fclean all

.PHONY: all clean fclean re
