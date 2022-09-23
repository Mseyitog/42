NAME = libftprintf.a
CC = gcc
FLAGS = -c -Wall -Wextra -Werror
RM = rm -rf

SOURCE = ft_printf.c \
		print_char.c \
		print_int.c \
		print_hex_upper.c \
		print_ptr.c \
		print_str.c \
		print_hex_lower.c \
		print_perc.c \
		print_unsigned_int.c

OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY = clean fclean all re