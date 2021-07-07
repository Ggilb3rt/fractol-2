O = obj/
I = inc/
S = src/
L = lib/
#B = $Sbonus/

include sources.mk
OBJ = $(SRC:$S%.c=$O%.o)
#BONUSOBJ = $(SRC_BONUS:$B.c=$O.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCFLAGS = -I$I
FRAMEWORKS = -framework OpenGL -framework AppKit -lz
LMLX = -lmlx -L./lib/minilibx_opengl

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
	$(CC) $^ -L./lib/libft -lft $(LMLX) $(FRAMEWORKS) -o $@
	./$(NAME) julia basic 1

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


