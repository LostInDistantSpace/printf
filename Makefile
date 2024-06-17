SRC		:= ft_printf.c			\
			ft_flags.c			\
			ft_flag_digits.c	\
			ft_print.c			\
			ft_print_char.c		\
			ft_print_s.c		\
			ft_print_u.c		\
			ft_print_nb.c		\
			ft_print_hex.c		\
			ft_print_padding.c	\
			ft_nbtoa.c			\
			ft_putnbr.c


NAME	:= libftprintf.a

LIBFT 	:= libft

INCLUDES := includes

OBJS	:= ${SRC:.c=.o}

CC		:= cc

AR		:= ar -rc

RM		:= rm -f

CFLAGS	:= -Wall -Wextra -Werror -g3 -I

all:	${NAME}

bonus: all

.c.o:
			@$(CC) $(CFLAGS) $(INCLUDES) -c  $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@make -C $(LIBFT)
	@mv $(LIBFT)/libft.a $(NAME)
	@${AR} ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}
	@make clean -C $(LIBFT)

fclean:	clean
	@${RM} ${NAME}
	@make fclean -C $(LIBFT)

re:		fclean all

.PHONY:	 all clean fclean re