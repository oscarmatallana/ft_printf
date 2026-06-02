NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCLUDES = -I .

SRC =	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putptr.c \
		ft_putnbr.c \
		ft_puthexa.c \
		ft_putunsigned.c

OBJS = $(SRC:.c=.o)

all: ${NAME}

$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
