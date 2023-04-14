NAME		=	philo

HEADER		=	./include/

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I -pthread

SRCS		=	srcs/main.c \
				srcs/activity.c \
				srcs/threads.c \
				srcs/init_and_parse.c \
				srcs/utils_philo.c \
				srcs/utils_lib.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				rm -rf $(OBJS)

clean		:
				rm -rf $(NAME)

fclean		:
				rm -rf $(NAME)

git			:
				git add .
				git status
				git commit -m "not now finished"
				git push

re			:	fclean all