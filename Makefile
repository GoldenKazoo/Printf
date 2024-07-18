NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf_nbr_utils.c ft_printf_utils.c ft_printf.c ft_printf_ptr.c

SRCSALL = ${SRCS}

INCS = .

OBJS = ${SRCS:.c=.o}

OBJSALL = ${OBJS} 

all: ${NAME}

.c.o:
		cc -I${INCS} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus: ${OBJSALL}
		ar rcs ${NAME} ${OBJSALL}

clean:
		-rm -f ${OBJSALL}

fclean: clean
		-rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re bonus