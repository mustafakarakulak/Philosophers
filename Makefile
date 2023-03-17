SRC = lib/arg_checker.c lib/arg_converter.c lib/utils.c \
		ft_philosophers.c lib/ft_init.c

NAME = philosophers

FLAG = -Wall -Wextra -Werror

all:
	gcc $(FLAG) $(SRC) -o $(NAME)


clean:
	rm $(NAME)

fclean: clean

re: clean all

git:
	git add .
	git status
	git commit -m "not finished"
	git push

.PHONY: git re fclean clean all