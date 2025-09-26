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

LIBFT_DIR = libft/
LIBFT_NAME = $(LIBFT_DIR)libft.a
LIB_FLAGS = -L$(LIBFT_DIR) -lft
HEADER = $(LIBFT_DIR)libft.h

CC = cc
FLAGS = -Wall -Werror -Wextra

MLX_DIR = minilibx-linux/
MLX_NAME = $(MLX_DIR)libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lXrandr

SRCS =	init.c			\
		args.c			\
		render.c		\
		events.c		\
		actions.c		\
		mandelbrot.c	\
		messages.c		\
		sets.c			\
		main.c			\

OBJS_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -c $< -o $@


$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(FLAGS) -O3 $(OBJS) $(MLX_FLAGS) $(LIB_FLAGS) -lm -o $(NAME)
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
