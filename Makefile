.PHONY:	all clean fclean re deps debug show_compiling_msg

#Files
LST_EXEC :=	minirt.c

LST_TEST :=	test_functions.c

LST_PARSING :=	check_object.c check_params.c fill_color.c fill_light.c fill_obj.c parsing.c

LST_CAMERA:=	init_camera.c

LST_RAY :=	ray.c

LST_RENDER :=	mlx_hooks.c mlx_init.c mlx_utils.c scene_init.c

LST_UTILS :=	close.c

LST_INC :=	minirt.h rt_structures.h \
			scene/camera.h scene/setup.h \
			utils/rt_utils.h

#Directories
D_SRC :=	src/
D_INC :=	include/
D_LIB :=	libs/
D_OBJ :=	.obj/

D_PARSING := parsing/
D_TEST :=	tests/

#Files full path
D_CAMERA :=	camera/
D_RENDER :=	render/
D_UTILS :=	utils/

#Files full path
SRC :=	$(addprefix $(D_SRC), $(LST_EXEC)) \
		$(addprefix $(D_SRC)$(D_CAMERA), $(LST_CAMERA)) \
		$(addprefix $(D_SRC)$(D_RENDER), $(LST_RENDER)) \
		$(addprefix $(D_SRC)$(D_UTILS), $(LST_UTILS)) \
		$(addprefix $(D_SRC)$(D_TEST), $(LST_TEST)) \
		$(addprefix $(D_SRC)$(D_PARSING), $(LST_PARSING))

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

D_DVECT := $(D_LIB)dynvect/
DVECT := $(D_DVECT)dynvect.a

# D_MVECT := $(D_LIB)mathvect/
# MVECT := $(D_MVECT)mathvect.a

#Variables
NAME := miniRT
CC := cc
CFLAGS := -Wall -Wextra -O3 # -Werror
IFLAGS := -I$(D_INC) -I$(D_LIBFT) -I$(D_LIBFT)/gnl -I$(D_LIBFT)/mylib -I$(D_DVECT) -I$(D_LIBMLX) -I$(D_LIBMATH)include/ #-I$(D_MVECT)
DEBUG_VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

RM := rm -rf
MAKE_CMD := @$(MAKE) --no-print-directory

#Compilation
-include $(DEPSFILES)

all: .print_header
	@echo "\n🚀 Building $(NAME) :"
	$(MAKE_CMD) deps show_compiling_msg $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(DVECT) $(MVECT) $(MLX) $(LIBMATH)
	@echo "✅ Compilation done.\n\n🔗 Linking $(NAME)..."
	@$(CC) $(OBJ) $(LIBFT) $(DVECT) $(MVECT) $(MLX) $(LIBMATH) -L/opt/X11/lib -lXext -lX11 -lm -o $@
	@echo "✅ Linking done.\n\n🎉 ./$(NAME) ready to run!\n"

$(D_OBJ)%.o: $(D_SRC)%.c $(INC) Makefile | $(D_OBJ)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -MMD -MP -c $< -o $@

$(D_OBJ):
	@mkdir -p $@

deps:
	@echo "\n🏗️  Building dependencies...\n\n📚 Building libft..."
	$(MAKE_CMD) -C $(D_LIBFT) > /dev/null 2>&1
	@echo "✅ Libft build done.\n\n📚 Building dynvector lib..."
	$(MAKE_CMD) -C $(D_DVECT) > /dev/null 2>&1
	@echo "✅ Dynvector lib build done.\n\n📚 Building math lib..."
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
	@echo "🧹 Full clean of $(NAME)..."
	$(MAKE_CMD) fclean -C $(D_LIBFT) > /dev/null 2>&1
	$(MAKE_CMD) fclean -C $(D_DVECT) > /dev/null 2>&1
	$(MAKE_CMD) fclean -C $(D_LIBMATH) > /dev/null 2>&1
	$(MAKE_CMD) clean -C $(D_LIBMLX) > /dev/null 2>&1
	@$(RM) $(NAME)
	@echo "✨ All clean!\n"

re: fclean all

show_compiling_msg:
	@echo "🛠️  Compiling $(NAME)..."

.print_header:
	$(call DISPLAY_TITLE)

########################################################################################################################
#                                                       COLORS                                                         #
########################################################################################################################

DEF_COLOR 	= \033[0;39m
GREEN		= \033[1;92m
BLUE		= \033[0;94m

########################################################################################################################
#                                                       DISPLAY                                                        #
########################################################################################################################

define DISPLAY_TITLE
						@echo "$(BLUE)  __  __ _____ _   _ _____ _____ _______ "
						@echo " |  \/  |_   _| \ | |_   _|  __ \__   __|"
						@echo " | \  / | | | |  \| | | | | |__| | | |   "
						@echo " | |\/| | | | | .   | | | |  _  /  | |   "
						@echo " | |  | |_| |_| |\  |_| |_| | \ \  | |   "
						@echo " |_|  |_|_____|_| \_|_____|_|  \_\ |_|   "
						@echo "$(GREEN)                   by ludebion & gaducurt$(DEF_COLOR)"
						@printf "\n"
endef
