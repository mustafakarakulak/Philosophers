NAME		=	philo

HEADER		=	./include/

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I -pthread

SRCS		=	src/activity.c \
				src/initialize.c \
				src/main.c \
				src/threads.c \
				src/utils.c \
				src/check.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:
				rm -rf $(NAME)
				rm -rf $(OBJS)

git			:
				git add .
				git status
				git commit -m "not now finished"
				git push

re			:	fclean all