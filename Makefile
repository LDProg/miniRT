.PHONY:	all clean fclean re deps debug show_compiling_msg

#Files
LST_EXEC :=	minirt.c

#Directories
D_SRC :=	src/
D_INC :=	include/
D_OBJ :=	.obj/

#Files full path
SRC :=	$(addprefix $(D_SRC), $(LST_EXEC))

OBJ :=	$(subst $(D_SRC), $(D_OBJ), $(SRC:.c=.o))

DEPSFILES :=	$(subst $(D_SRC), $(D_OBJ), $(SRC:.o=.d))

#Libraries
D_LIBFT :=	libft/
LIBFT := $(D_LIBFT)libft.a

D_LIBMLX := minilibx-linux/
MLX := $(D_LIBMLX)libmlx.a

#Variables
NAME := miniRT
CC := cc
CFLAGS := -Wall -Wextra -Werror -O3
IFLAGS := -I$(D_INC) -I$(D_LIBFT) -I$(D_LIBMLX)
DEBUG_VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

RM := rm -rf
MAKE_CMD := @$(MAKE) --no-print-directory

#Compilation
all:
	@echo "\n🚀 Building $(NAME) :"
	$(MAKE_CMD) deps show_compiling_msg $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "✅ Compilation done.\n\n🔗 Linking $(NAME)..."
	@$(CC) $(OBJ) $(LIBFT) $(MLX) -L/opt/X11/lib -lXext -lX11 -lm -o $@
	@echo "✅ Linking done.\n\n🎉 ./$(NAME) ready to run!\n"

$(D_OBJ)%.o: $(D_SRC)%.c Makefile | $(D_OBJ)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -MMD -MP -c $< -o $@

$(D_OBJ):
	@mkdir -p $@

deps:
	@echo "\n🏗️  Building dependencies...\n\n📚 Building libft..."
	$(MAKE_CMD) -C $(D_LIBFT) > /dev/null 2>&1
	@echo "✅ Libft build done.\n\n📚 Building mlx..."
	@cp configure_mlx_no_tests $(D_LIBMLX)configure
	$(MAKE_CMD) -C $(D_LIBMLX) > /dev/null 2>&1
	@git -C $(D_LIBMLX) checkout configure 2>/dev/null || true
	@echo "✅ MLX build done.\n\n✅ Dependencies build done.\n"

debug: all
	$(DEBUG_VALGRIND) ./$(NAME) $(ARGS)

clean:
	@echo "\n🧹 Cleaning $(NAME) object files..."
	@$(RM) $(D_OBJ)
	@echo "✅ Object files removed.\n"

fclean: clean
	@echo "🧹 Cleaning libft, minilibx, and $(NAME)..."
	$(MAKE_CMD) fclean -C $(D_LIBFT) > /dev/null 2>&1
	$(MAKE_CMD) clean -C $(D_LIBMLX) > /dev/null 2>&1
	@$(RM) $(NAME)
	@echo "✨ All clean!\n"

re: fclean all

show_compiling_msg:
	@echo "🛠️  Compiling $(NAME)..."
