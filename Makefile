#################################################################################
################					MAKEFILE					#################
#################################################################################

.PHONY:	all clean fclean re deps bonus show_compiling_msg
NAME :=	miniRT

#################################################################################
################					FILE TREE					#################
#################################################################################

#Files
LST_EXEC :=	minirt.c	\
			manage_window.c	\
			parsing/parsing.c	\
			parsing/check_object.c	\
			parsing/check_params.c	\
			parsing/multi_split.c	\
			test_functions.c	\

# LST_UTILS :=	kill_program.c float_utils.c hooks.c

LST_INC :=	minirt.h	\
			struct.h	\

#Directories
D_SRC :=	src/
D_INC :=	include/

# D_RENDERING :=	rendering/
# D_UTILS :=	utils/

D_OBJ :=	.obj/

#Files full path
SRC :=	$(addprefix $(D_SRC), $(LST_EXEC)) \
		# $(addprefix $(D_SRC)$(D_RENDERING), $(LST_RENDERING)) \
		# $(addprefix $(D_SRC)$(D_UTILS), $(LST_UTILS))

INC :=	$(addprefix $(D_INC), $(LST_INC))

OBJ :=	$(subst $(D_SRC), $(D_OBJ), $(SRC:.c=.o))
DEPS :=	$(OBJ:.o=.d)

#Libraries
D_LIBFT :=	libft/
LIBFT := $(D_LIBFT)libft.a

D_LIBMLX := minilibx-linux/
MLX := $(D_LIBMLX)libmlx.a

D_VECT := vector/
VECT := $(D_VECT)vector.a

#################################################################################
################				BASIC VARIABLES					#################
#################################################################################

CC := cc
CFLAGS := -Wall -Wextra -Ofast -funroll-loops -g3
IFLAGS := -I$(D_INC) -I$(D_LIBFT) -I$(D_LIBFT)/gnl -I$(D_LIBMLX) -I$(D_VECT)

RM := rm -rf
MAKE_CMD := @$(MAKE) --no-print-directory

#################################################################################
################					RULES						#################
#################################################################################

# Step 1 : Full compilation
all:
	@echo "\n🚀 Building $(NAME) :"
	$(MAKE_CMD) deps show_compiling_msg $(NAME)

# Step 4 : Links edition (Linking)
$(NAME): $(OBJ) $(LIBFT) $(MLX) $(VECT)
	@echo "✅ Compilation done.\n\n🔗 Linking $(NAME)..."
	@$(CC) $(OBJ) $(LIBFT) $(MLX) -L/opt/X11/lib -lXext -lX11 -lm -o $@
	@echo "✅ Linking done.\n\n🎉 ./$(NAME) ready to run!\n"

# Step 2 & 3 : Compilation + Assembly (Generate all .o)
$(D_OBJ)%.o: $(D_SRC)%.c $(INC) Makefile | $(D_OBJ)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# $(D_OBJ):
# 	@mkdir -p $@/$(D_RENDERING) $@/$(D_UTILS)

$(D_OBJ):
	@mkdir -p $(D_OBJ)
	@mkdir -p $(D_OBJ)/parsing

# Step 1.5 : Compilation of libft and mlx
deps:
	@echo "\n🏗️  Building dependencies...\n\n📚 Building libft..."
	$(MAKE_CMD) -C $(D_LIBFT)
	@echo "✅ Libft build done.\n\n📚 Building vector..."
	@echo "\n🏗️  Building dependencies...\n\n📚 Building vector..."
	$(MAKE_CMD) -C $(D_VECT)
	@echo "✅ Vector build done.\n\n📚 Building mlx..."
	$(MAKE_CMD) -C $(D_LIBMLX)
	@echo "✅ MLX build done.\n\n✅ Dependencies build done.\n"

# Step 5 : Cleaning object files
clean:
	@echo "\n🧹 Cleaning $(NAME) object files..."
	@$(RM) $(D_OBJ)
	@echo "✅ Object files removed.\n"

# Step 6 : Full clean (libft + mlx + executable)
fclean: clean
	@echo "🧹 Cleaning libft, minilibx, and $(NAME)..."
	$(MAKE_CMD) fclean -C $(D_LIBFT) > /dev/null 2>&1
	$(MAKE_CMD) fclean -C $(D_VECT) > /dev/null 2>&1
	$(MAKE_CMD) clean -C $(D_LIBMLX) > /dev/null 2>&1
	@$(RM) $(NAME)
	@echo "✨ All clean!\n"

# Step 7 : Full recompilation
re: fclean all

show_compiling_msg:
	@echo "🛠️  Compiling $(NAME)..."

-include $(DEPS)
