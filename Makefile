
NAME		= libftprintf.a
LIB_PATH	= ./libft
LIB			= libft.a
INCLUDES	= ./includes

SRCS		= 	source/ft_printf.c \
				source/ft_do_type.c \
				source/ft_do_flags.c \
				source/ft_do_c_or_procent.c \
				source/ft_do_di.c \
				source/ft_do_ouxX.c \
				source/ft_do_p.c \
				source/ft_do_s.c \
				source/ft_do_type.c \
				source/ft_isset.c \
				source/ft_itoa_base.c \
				source/ft_llitoa.c \
				source/ft_parse_specification.c \
				source/ft_puts.c \
				source/ft_strupper.c \
				source/ft_help_flags.c \

OBJS		= $(SRCS:.c=.o)

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

.c.o:
			$(GCC) $(CFLAGS) -I$(LIB_PATH) -c $< -o $@

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIB_PATH)
			$(MAKE) bonus -C $(LIB_PATH)
			cp ${LIB_PATH}/${LIB} ${NAME}
			ar -rc $(NAME) $(OBJS)
			ranlib $(NAME)
			$(MAKE) clean

bonus:		all

clean:
			$(MAKE) clean -C $(LIB_PATH)
			rm -f $(OBJS) $(OBJS_B)

fclean:		clean
			$(MAKE) fclean -C $(LIB_PATH)
			rm -f $(NAME)

re:			fclean all
			$(MAKE) re -C $(LIB_PATH)

.PHONY : all clean fclean re bonus