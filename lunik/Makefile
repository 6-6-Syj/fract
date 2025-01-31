COLOR_BLACK = \033[30m
COLOR_RED = \033[31m
COLOR_GREEN = \033[32m
COLOR_YELLOW = \033[33m
COLOR_BLUE = \033[34m
COLOR_MAGENTA = \033[35m
COLOR_CYAN = \033[36m
COLOR_WHITE = \033[37m
COLOR_BOLD = \033[1m
COLOR_RESET = \033[0m

NAME = fractol

# Répertoire, nom et header de la bibliothèque libft
LIBFT_DIR = libft/
LIBFT_NAME = $(LIBFT_DIR)libft.a
HEADER = $(LIBFT_DIR)libft.h

CC = cc
FLAGS = -Wall -Werror -Wextra

# Répertoire, nom et header de la bibliothèque mlx
MLX_DIR = minilibx-linux/
MLX_NAME = $(MLX_DIR)libmlx.a
MLX_FLAGS = -L $(MLX_DIR) -lXext -lX11 -lmlx_Linux $(MLX_NAME)

SRCS =	init.c			\
		fractol.c		\
		render.c		\
		events.c		\
		mandelbrot.c	\
		mandelbox.c		\
		messages.c		\
		sets.c			\

OBJS_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -c $< -o $@


$(NAME): $(OBJS)
# create libft.a
	@make -C $(LIBFT_DIR)
# create mlx.a
	@make -C $(MLX_DIR)
# Compilation de l'exécutable final avec les objets et les bibliothèques
# Tester de compiler avec -g3 (plus rapide apparement)
	$(CC) $(FLAGS) -g3 -lm $(OBJS) -L$(LIBFT_DIR) $(LIBFT_NAME) $(MLX_FLAGS) -o $(NAME)
	@echo "\n✅$(COLOR_BOLD)$(COLOR_GREEN) $(LIBFT_NAME) ✅\n✅ $(MLX_NAME) ✅\n✅ $(NAME) has been created$(COLOR_RESET) ✅\n"

clean :
	@rm -rf $(OBJS_DIR) $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean : clean
	@rm -f $(LIBFT_NAME) $(MLX_NAME)
	@$(RM) $(NAME)
	@echo "\n❌$(COLOR_BOLD)$(COLOR_RED) $(LIBFT_NAME) ❌\n❌ $(MLX_NAME) ❌\n❌ $(NAME) have been deleted$(COLOR_RESET) ❌\n"

re : fclean all

.PHONY : clean fclean re name
