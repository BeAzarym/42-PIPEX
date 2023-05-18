NAME	=	pipex

SRC =	main.c \
		exec.c \
		utils/ft_error.c \
		utils/init_struct.c \
		parsing/parsing.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(SRCS:.c=.o)

LIBFT = make -C ./src/libft

SRC_DIR = src
INC_DIR = include

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = @rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(LIBFT)
	$(CC) $(CLFAGS) -Isrc/libft -I $(INC_DIR) -o $(NAME) $(OBJS) -Lsrc/libft -lft

clean:
	$(RM) $(OBJS)
	make -C ./src/libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./src/libft fclean

re: fclean all

.PHONY: all re clean fclean