NAME = libftprintf.a

SRCS =  src/ft_putchar.c src/ft_putstr.c src/ft_putnbr.c src/ft_putlnbr_base.c src/ft_putunbr_base.c \
 	src/ft_check_base.c src/ft_string_format.c src/ft_integer_format.c src/ft_pointer_format.c src/ft_unsigned_format.c \
	src/ft_hex_format.c src/ft_printf.c src/ft_helper.c

LIBFT_SRCS = ./Libft/ft_lstnew.c ./Libft/ft_lstadd_front.c ./Libft/ft_lstsize.c ./Libft/ft_lstlast.c \
./Libft/ft_lstadd_back.c ./Libft/ft_lstdelone.c ./Libft/ft_lstclear.c ./Libft/ft_lstiter.c \
./Libft/ft_lstmap.c ./Libft/ft_isalpha.c ./Libft/ft_isdigit.c ./Libft/ft_isalnum.c ./Libft/ft_isascii.c \
./Libft/ft_isprint.c ./Libft/ft_strlen.c ./Libft/ft_memset.c ./Libft/ft_bzero.c ./Libft/ft_memcpy.c ./Libft/ft_memmove.c \
./Libft/ft_strlcpy.c ./Libft/ft_strlcat.c ./Libft/ft_toupper.c ./Libft/ft_tolower.c ./Libft/ft_strchr.c \
./Libft/ft_strrchr.c ./Libft/ft_strncmp.c ./Libft/ft_memchr.c ./Libft/ft_memcmp.c ./Libft/ft_strnstr.c \
./Libft/ft_atoi.c ./Libft/ft_calloc.c ./Libft/ft_strdup.c ./Libft/ft_substr.c ./Libft/ft_strjoin.c \
./Libft/ft_strtrim.c ./Libft/ft_split.c ./Libft/ft_itoa.c ./Libft/ft_strmapi.c ./Libft/ft_striteri.c \
./Libft/ft_putchar_fd.c ./Libft/ft_putstr_fd.c ./Libft/ft_putendl_fd.c ./Libft/ft_putnbr_fd.c



OBJS = ${SRCS:.c=.o}

LIBFT_OBJS = ${LIBFT_SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR = ar rcs

Libft = ./Libft/libft.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_OBJS}
	$(MAKE) bonus -C ./Libft
	cp ./Libft/libft.a $(NAME)
	${AR} ${NAME} ${OBJS}

%.o: %.c
	$(CC) -fPIC $(CFLAGS) -c $< -o $@
	
bonus: all
	
clean:
	$(MAKE) clean -C ./Libft
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 
	${RM} ./Libft/libft.a

re: fclean all

.PHONY:	all clean fclean re bonus
