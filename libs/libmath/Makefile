.PHONY:	all clean fclean re

#Files
LST_SRCS_MAT4 :=	mat4_init.c mat4_ops.c mat4_trsf.c mat4_print.c

LST_SRCS_VEC3 :=	tuple_cmp.c tuple_init.c tuple_ops.c vec3_ops.c vec3_ops2.c vec3_print.c

LST_INC :=	libmath.h libmath_structures.h

#Directories
D_SRCS :=	srcs/
D_INC :=	includes/
D_OBJS :=	.objs/

D_MATRICE := matrice/
D_VECTOR := vector/
D_MATRIX_G := matrix_gaducurt/
D_VECTOR_G := vector_gaducurt/

D_MAT4 := mat4/
D_VEC3 := vec3/

#Files full path
SRCS :=	$(addprefix $(D_SRCS)$(D_MAT4), $(LST_SRCS_MAT4)) \
		$(addprefix $(D_SRCS)$(D_VEC3), $(LST_SRCS_VEC3))	\

INC :=	$(addprefix $(D_INC), $(LST_INC))

OBJS :=	$(subst $(D_SRCS), $(D_OBJS), $(SRCS:.c=.o))

DEPSFILES :=	$(subst $(D_SRCS), $(D_OBJS), $(SRCS:.o=.d))

#Variables
NAME :=	libmath.a
CC :=	cc
C_FLAGS :=	-Wall -Wextra -Werror -O3

RM :=	rm -rf

#Rules
-include $(DEPSFILES)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

$(D_OBJS)%.o: $(D_SRCS)%.c $(INC) Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(D_INC) -MMD -MP -c $< -o $@

clean:
	$(RM) $(D_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)
