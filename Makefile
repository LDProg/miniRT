.PHONY:	all clean fclean re deps debug show_compiling_msg

#Files
LST_EXEC :=		minirt.c

LST_PARSING :=	check_args.c parse_file.c parse_obj.c parse_scene.c parse_utils.c \
				split_charset.c ft_atoi_safe.c ft_atof_safe.c

LST_RENDER :=	camera.c raytrace.c

LST_INTERSECT_SHAPES := cylinder.c plane.c sphere.c

LST_MLX_WINDOW :=	mlx_hooks.c mlx_init.c mlx_utils.c

LST_UTILS :=	close.c color.c print.c quadratic.c

LST_TEST :=		test_functions.c

LST_INTER :=	intersect_sphere.c intersect_plan.c find_intersect.c compute_color.c


LST_INC :=	minirt.h rt_structures.h \
			scene/mlx_window.h scene/render.h \
			utils/rt_utils.h

#Directories
D_SRCS :=	srcs/
D_INC :=	includes/
D_LIB :=	libs/
D_OBJS :=	.objs/

D_PARSING := parsing/
D_TEST :=	tests/

#Files full path
D_CAMERA :=	camera/
D_MLX_WINDOW :=	mlx_window/
D_RENDER :=	render/
D_INTERSECT_SHAPES := intersect_shapes/
D_UTILS :=	utils/
D_INTER := intersect/

#Files full path
SRCS :=	$(addprefix $(D_SRCS), $(LST_EXEC)) \
		$(addprefix $(D_SRCS)$(D_PARSING), $(LST_PARSING)) \
		$(addprefix $(D_SRCS)$(D_RENDER), $(LST_RENDER)) \
		$(addprefix $(D_SRCS)$(D_RENDER)$(D_INTERSECT_SHAPES), $(LST_INTERSECT_SHAPES)) \
		$(addprefix $(D_SRCS)$(D_RENDER)$(D_MLX_WINDOW), $(LST_MLX_WINDOW)) \
		$(addprefix $(D_SRCS)$(D_UTILS), $(LST_UTILS)) \
		$(addprefix $(D_SRCS)$(D_TEST), $(LST_TEST)) \
		$(addprefix $(D_SRCS)$(D_INTER), $(LST_INTER))\

INC :=	$(addprefix $(D_INC), $(LST_INC))

OBJS :=	$(subst $(D_SRCS), $(D_OBJS), $(SRCS:.c=.o))

DEPSFILES :=	$(subst $(D_SRCS), $(D_OBJS), $(SRCS:.o=.d))

#Libraries
D_LIBFT :=	$(D_LIB)libft/
LIBFT := $(D_LIBFT)libft.a

D_LIBMATH := $(D_LIB)libmath/
LIBMATH := $(D_LIBMATH)libmath.a

D_LIBMLX := $(D_LIB)minilibx-linux/
MLX := $(D_LIBMLX)libmlx.a

D_DVECT := $(D_LIB)dynvect/
DVECT := $(D_DVECT)dynvect.a

#Variables
NAME := miniRT
CC := cc
CFLAGS := -Wall -Wextra -Werror -O3 -g3
IFLAGS := -I$(D_INC) -I$(D_LIBFT) -I$(D_LIBFT)/gnl -I$(D_LIBFT)/mylib -I$(D_DVECT) -I$(D_LIBMLX) -I$(D_LIBMATH)includes/
DEBUG_VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

RM := rm -rf
MAKE_CMD := @$(MAKE) --no-print-directory

#Compilation
-include $(DEPSFILES)

all:
	@echo "\n🚀 Building $(NAME) :"
	$(MAKE_CMD) deps show_compiling_msg $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(DVECT) $(MVECT) $(MLX) $(LIBMATH)
	@echo "✅ Compilation done.\n\n🔗 Linking $(NAME)..."
	@$(CC) $(OBJS) $(LIBFT) $(DVECT) $(MVECT) $(MLX) $(LIBMATH) -L/opt/X11/lib -lXext -lX11 -lm -o $@
	@echo "✅ Linking done.\n\n🎉 ./$(NAME) ready to run!\n"

$(D_OBJS)%.o: $(D_SRCS)%.c $(INC) Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -MMD -MP -c $< -o $@

deps:
	@echo "\n🏗️  Building dependencies...\n\n📚 Building libft..."
	$(MAKE_CMD) -C $(D_LIBFT)
	@echo "✅ Libft build done.\n\n📚 Building dynvector lib..."
	$(MAKE_CMD) -C $(D_DVECT)
	@echo "✅ Dynvector lib build done.\n\n📚 Building math lib..."
	$(MAKE_CMD) -C $(D_LIBMATH)
	@echo "✅ Math lib build done.\n\n📚 Building mlx..."
	@cp configure_mlx_no_tests $(D_LIBMLX)configure
	$(MAKE_CMD) -C $(D_LIBMLX)
	@git -C $(D_LIBMLX) checkout configure 2>/dev/null || true
	@echo "✅ MLX build done.\n\n✅ Dependencies build done.\n"

debug: all
	$(DEBUG_VALGRIND) ./$(NAME) $(ARGS)

clean:
	@echo "\n🧹 Cleaning $(NAME) objSect files..."
	@$(RM) $(D_OBJS)
	@echo "✅ ObjSect files removed.\n"

fclean: clean
	@echo "🧹 Full clean of $(NAME)..."
	$(MAKE_CMD) fclean -C $(D_LIBFT)
	$(MAKE_CMD) fclean -C $(D_DVECT)
	$(MAKE_CMD) fclean -C $(D_LIBMATH)
	$(MAKE_CMD) clean -C $(D_LIBMLX)
	@$(RM) $(NAME)
	@echo "✨ All clean!\n"

re: fclean all

show_compiling_msg:
	@echo "🛠️  Compiling $(NAME)..."
