NAME		=	philo_bonus

HEADER		=	./include/

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I -pthread

SRCS		=	srcs/initialize.c \
				srcs/parsing.c \
				srcs/main.c \
				srcs/activity.c \
				srcs/check.c \
				srcs/threads.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:
				rm -rf $(NAME) $(OBJS)

re			:	fclean all