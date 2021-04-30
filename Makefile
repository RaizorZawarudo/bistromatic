##
## EPITECH PROJECT, 2020
## Makefile for eval_expr
## File description:
## Makefile
##

CFLAGS = -g3 -W -Wall -Wextra

SRC = main.c \
	add_substract/add.c \
	add_substract/substract.c \
	add_substract/add_substract_utilities.c \
	general_utilities/general_utilities.c \
	multiply/multiply.c \
	evalexp_unmod/convert_input_to_array.c \
	evalexp_unmod/postfix_calculator.c \
	evalexp_unmod/postfix_creating_tools.c \
	evalexp_unmod/postfix_creator.c \
	evalexp_unmod/utility_functions.c \
	evalexp_unmod/inputcleaner.c \
	calculation.c\
	check_error.c\
	convert_base.c\
	divide_modulo/divide.c\
	divide_modulo/divide_utility.c\

OBJ = $(SRC:.c=.o)

NAME = calc

all: $(NAME) clean

$(NAME): $(OBJ)
	cd lib/my/ && make
	cd ../..
	gcc -o $(NAME) $(OBJ) -I./include -L./lib -lmy

clean:
	cd lib/my && make clean
	cd ../..
	rm -f $(OBJ)

fclean: clean
	cd lib/my && make fclean
	cd ../..
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re