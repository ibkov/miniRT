NAME = miniRT.a

TEST = miniRT

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_L = srcs/

INCLUDES = -I includes/ -I libft/

LIST = 		miniRT.c


OBJS =$(SRCS:.c=.o)

SRCS = $(addprefix $(DIR_L), $(LIST))

all: $(NAME)

$(NAME): my_lib $(OBJS)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

my_lib: 
	make -C $(LIBFT)

%.o: %.c includes/ft_printf.h
	gcc -g $(FLAGS) $(INCLUDES) -c $< -o $@

test: $(NAME)
	gcc -g $(INCLUDES) srcs/main.c -lftprintf -L. -o $(TEST)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

tclean:
	rm $(TEST)

re: fclean all

.PHONY: fclean re norme all clean