NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f


SRCS = ./src/actions.c ./src/main.c ./src/sort.c ./libft/ft_lstsize.c ./libft/ft_lstnew.c ./libft/ft_lstadd_back.c ./libft/ft_putstr_fd.c ./libft/ft_split.c ./libft/ft_strjoin.c ./libft/ft_putchar_fd.c ./libft/ft_strdup.c ./libft/ft_strlen.c\
	./src/actions2.c ./src/sort2.c ./src/utils2.c ./src/utils3.c ./src/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c ../libft.h ./push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

$(NAME): $(OBJS)
	$(CC) $^ -o $(NAME)