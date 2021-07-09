O = obj/
I = inc/
S = src/
L = lib/

include sources.mk
OBJ = $(SRC:$S%.c=$O%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCFLAGS = -I$I
FRAMEWORKS = -framework OpenGL -framework AppKit -lz
LMLX = -lmlx -L./lib/minilibx_opengl
LLIBFT = -L./lib/libft -lft

RM = rm -f

.PHONY: all clean fclean re


# MAKERS
all: $(NAME)

$O:
	@mkdir -p $@

$(OBJ): | $O

$O%.o: $S%.c $(HEADERS) | $O
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make bonus -C lib/libft/
	make -C lib/minilibx_opengl/
	$(CC) $^ $(LLIBFT) $(LMLX) $(FRAMEWORKS) -o $@
	./$(NAME) julia rainbow

# CLEANERS
cleanobj:
	$(RM) $(wildcard $(OBJ))
clean: cleanobj
	#$(RM) -r $(O)
fclean: clean
	$(RM) $(NAME)
re: fclean all

fcleanlibft:
	make fclean -C lib/libft/
fcleanall: fclean fcleanlibft
reall: fcleanall all

#LINUX
L_MLX_PATH = ./lib/minilibx-linux/
L_LMLX = -lmlx -L$(L_MLX_PATH)
L_MLX_NAME = $(L_MLX_PATH)libmlx.a
L_FRAMEWORKS = -lXext -lX11 -lm -lbsd

linux: $(OBJ)
	make bonus -C lib/libft/
	make -C lib/minilibx-linux/
	$(CC) $^ $(LLIBFT) $(L_MLX_NAME) $(L_LMLX) $(L_FRAMEWORKS) -o $(NAME)