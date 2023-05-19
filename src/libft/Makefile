NAME	=	libft.a

SRCS	=	ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_islower.c \
					ft_isupper.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_substr.c \
					ft_strtrim.c \
					ft_strjoin.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_printf_utils.c \
					ft_printf.c \
					get_next_line.c \
					ft_array_dup.c \
					ft_array_print.c \
					ft_array_clear.c \
					ft_array_join.c \
					ft_strjoin_array.c \
					ft_arraylen.c \
					ft_free.c \

SRCS_BONUS = ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstmap_bonus.c \
					ft_lstnew_bonus.c \
					ft_lstsize_bonus.c \
					


OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC	=	gcc

RM	=	@rm -fr

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
		ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)

$(NAME):	$(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all re clean fclean bonus