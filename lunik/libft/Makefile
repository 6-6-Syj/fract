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

NAME = libft.a

SRCS = ft_atof.c		\
	ft_atoi.c			\
	ft_bzero.c			\
	ft_calloc.c			\
	ft_isalnum.c		\
	ft_isalpha.c		\
	ft_isascii.c		\
	ft_isdigit.c		\
	ft_isprint.c		\
	ft_isspace.c		\
	ft_itoa.c			\
	ft_memchr.c			\
	ft_memcmp.c			\
	ft_memcpy.c			\
	ft_memmove.c		\
	ft_memset.c			\
	ft_strlcat.c		\
	ft_strlcpy.c		\
	ft_strlen.c			\
	ft_strmapi.c		\
	ft_split.c			\
	ft_strchr.c			\
	ft_strdup.c			\
	ft_striteri.c		\
	ft_strjoin.c		\
	ft_strncmp.c		\
	ft_strnstr.c		\
	ft_strrchr.c		\
	ft_strtrim.c		\
	ft_substr.c			\
	ft_toupper.c		\
	ft_tolower.c		\
	ft_putchar_fd.c		\
	ft_putendl_fd.c		\
	ft_putnbr_fd.c		\
	ft_putstr_fd.c		\
	ft_printf.c			\
	ft_printf_utils.c	\
	ft_printf_extend.c	\
	ft_printf_float.c	\
	get_next_line.c		\

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
HEADER = libft.h
AR = ar
ARFLAGS = -r -c -s

OBJS_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)


$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean :
	@$(RM) -r $(OBJS_DIR) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean re name
