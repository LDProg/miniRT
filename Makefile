.PHONY:	all clean fclean re deps debug show_compiling_msg

#Files
LST_EXEC :=	minirt.c

LST_MLX_WINDOW :=	mlx_hooks.c mlx_init.c mlx_utils.c

LST_PARSING:=	create_obj.c

LST_RENDER:=	camera.c intersect.c raytrace.c

LST_UTILS :=	close.c

LST_INC :=	minirt.h rt_structures.h \
			parsing/parsing.h \
			scene/mlx_window.h scene/render.h \
			utils/rt_utils.h

#Directories
D_SRC :=	src/
D_INC :=	include/
D_LIB :=	libs/
D_OBJ :=	.obj/

D_MLX_WINDOW :=	mlx_window/
D_PARSING :=	parsing/
D_RENDER :=	render/
D_UTILS :=	utils/

#Files full path
SRC :=	$(addprefix $(D_SRC), $(LST_EXEC)) \
		$(addprefix $(D_SRC)$(D_MLX_WINDOW), $(LST_MLX_WINDOW)) \
		$(addprefix $(D_SRC)$(D_PARSING), $(LST_PARSING)) \
		$(addprefix $(D_SRC)$(D_RENDER), $(LST_RENDER)) \
		$(addprefix $(D_SRC)$(D_UTILS), $(LST_UTILS))

INC :=	$(addprefix $(D_INC), $(LST_INC))

OBJ :=	$(subst $(D_SRC), $(D_OBJ), $(SRC:.c=.o))

DEPSFILES :=	$(subst $(D_SRC), $(D_OBJ), $(SRC:.o=.d))

#Libraries
D_LIBFT :=	$(D_LIB)libft/
LIBFT := $(D_LIBFT)libft.a

D_LIBMATH := $(D_LIB)libmath/
LIBMATH := $(D_LIBMATH)libmath.a

D_LIBMLX := $(D_LIB)minilibx-linux/
MLX := $(D_LIBMLX)libmlx.a

#Variables
NAME := miniRT
CC := cc
CFLAGS := -Wall -Wextra -O3
IFLAGS := -I$(D_INC) -I$(D_LIBFT) -I$(D_LIBMLX) -I$(D_LIBMATH)include/
DEBUG_VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

RM := rm -rf
MAKE_CMD := @$(MAKE) --no-print-directory

#Compilation
all:
	@echo "\n🚀 Building $(NAME) :"
	$(MAKE_CMD) deps show_compiling_msg $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMATH) $(MLX)
	@echo "✅ Compilation done.\n\n🔗 Linking $(NAME)..."
	@$(CC) $(OBJ) $(LIBFT) $(LIBMATH) $(MLX) -L/opt/X11/lib -lXext -lX11 -lm -o $@
	@echo "✅ Linking done.\n\n🎉 ./$(NAME) ready to run!\n"

$(D_OBJ)%.o: $(D_SRC)%.c $(INC) Makefile | $(D_OBJ)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -MMD -MP -c $< -o $@

$(D_OBJ):
	@mkdir -p $@

deps:
	@echo "\n🏗️  Building dependencies...\n\n📚 Building libft..."
	$(MAKE_CMD) -C $(D_LIBFT) > /dev/null 2>&1
	@echo "✅ Libft build done.\n\n📚 Building math lib..."
	$(MAKE_CMD) -C $(D_LIBMATH) > /dev/null 2>&1
	@echo "✅ Math lib build done.\n\n📚 Building mlx..."
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
	$(MAKE_CMD) fclean -C $(D_LIBMATH) > /dev/null 2>&1
	$(MAKE_CMD) clean -C $(D_LIBMLX) > /dev/null 2>&1
	@$(RM) $(NAME)
	@echo "✨ All clean!\n"

re: fclean all

show_compiling_msg:
	@echo "🛠️  Compiling $(NAME)..."
