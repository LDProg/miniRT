.PHONY:	all clean fclean re

#Files
LST_SRC_MAT4 :=	mat4_init.c mat4_ops.c mat4_trsf.c mat4_print.c

LST_SRC_VEC3 :=	tuple_cmp.c tuple_init.c tuple_ops.c vec3_ops.c vec3_ops2.c vec3_print.c

LST_SRC_MATRIX_G := all_rotate_matrix.c rotate_x.c rotate_y.c rotate_z.c scaling_matrix.c translate_matrix.c

LST_SRC_VECTOR_G := add_vect_point.c cross_product.c dot_product.c init_tuple.c inv_tup.c normalize_vect.c \
					scalar_div.c scalar_mult.c sub_point_vect.c sub_two_points.c sub_two_vect.c vect_mag.c \
					position.c 

LST_INC :=	libmath.h libmath_structures.h mathvect.h

#Directories
D_SRC :=	src/
D_INC :=	include/
D_OBJ :=	.obj/

D_MATRICE := matrice/
D_VECTOR := vector/
D_MATRIX_G := matrix_gaducurt/
D_VECTOR_G := vector_gaducurt/

D_MAT4 := mat4/
D_VEC3 := vec3/

#Files full path
SRC :=	$(addprefix $(D_SRC)$(D_MATRIX_G), $(LST_SRC_MATRIX_G)) \
		$(addprefix $(D_SRC)$(D_VECTOR_G), $(LST_SRC_VECTOR_G)) \
		$(addprefix $(D_SRC)$(D_MAT4), $(LST_SRC_MAT4)) \
		$(addprefix $(D_SRC)$(D_VEC3), $(LST_SRC_VEC3)) 

INC :=	$(addprefix $(D_INC), $(LST_INC))

OBJ :=	$(subst $(D_SRC), $(D_OBJ), $(SRC:.c=.o))

DEPSFILES :=	$(subst $(D_SRC), $(D_OBJ), $(SRC:.o=.d))

#Variables
NAME :=	libmath.a
CC :=	cc
C_FLAGS :=	-Wall -Wextra -Werror -O3

RM :=	rm -rf

#Rules
-include $(DEPSFILES)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

$(D_OBJ)%.o: $(D_SRC)%.c $(INC) Makefile | $(D_OBJ)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(D_INC) -MMD -MP -c $< -o $@

$(D_OBJ):
	@mkdir -p $@

clean:
	@$(RM) $(D_OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean $(NAME)
