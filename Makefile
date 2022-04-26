##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile eval expr with libmy
##

SRC	=	evalexpr.c	\
		fct_evalexpr.c	\
		calc_str_without_parent.c	\
		error_handling_bistro.c	\
		main_bistro.c	\
		error_handling2.c	\

SRC_TESTS	=	evalexpr.c	\
			fct_evalexpr.c  \
			calc_str_without_parent.c       \
			error_handling_bistro.c	\
			error_handling2.c      	\

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

.PHONY : all clean fclean re test_run

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(OBJ) -L lib/my/ -o $(NAME) -lmy

clean:
	rm -f *.o
	rm -f *~
	rm -f *.gcda
	rm -f *.gcno
	make clean -C lib/my
	rm -f ./a.out

fclean:	clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all

tests_run:
	make -C lib/my
	gcc $(SRC_TESTS) -L lib/my -lmy ./tests/test.c --coverage -lcriterion
	./a.out
