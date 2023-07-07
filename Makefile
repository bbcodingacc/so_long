NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror
FREAMS = -framework OpenGL -framework AppKit

FILE = control error loop main read_map utils valid_map
OBJS = $(addsuffix .o, $(FILE))
SRCS = $(addsuffix .c, $(FILE))
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(FREAMS)

%.o: %.c
	$(CC) -c $^ -o $@

$(LIBFT):
	@make -C ./libft

$(MLX):
	@make -C ./mlx 

clean:
	rm $(OBJS)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY = al clean fclean re
		