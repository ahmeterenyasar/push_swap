NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	operations.c \
	parser.c \
	sorting.c \
	stack.c \
	utils.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re