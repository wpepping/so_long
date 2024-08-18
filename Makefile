SRCS = events.c libft_utils.c movement.c read_map.c render.c shoot.c so_long.c textures.c utils.c validate_map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

LIB_FOLDER = minilibx
LIB_ARCHIVE = libmlx.a
LIB_INCLUDE = mlx

CFLAGS = -Wall -Werror -Wextra
INCLUDES = -L$(LIB_FOLDER) -l$(LIB_INCLUDE) -lm -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_FOLDER)
	cc $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) clean -C $(LIB_FOLDER)
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
