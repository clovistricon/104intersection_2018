NAME	= 104intersection

CC	= gcc -lm

RM	= rm -f

SRCS	= ./intersection.c \
	  ./my_getnbr.c \
	  ./my_putchar.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
