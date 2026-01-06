.PHONY:	all clean fclean re

#Files
LST_SRC_MATRICE :=	mat4_init.c mat4_ops.c mat4_trsf.c mat4_print.c

LST_SRC_VEC3 :=	tuple_cmp.c tuple_init.c tuple_ops.c vec3_ops.c vec3_ops2.c vec3_print.c

LST_INC :=	libmath.h libmath_structures.h

#Directories
D_SRC :=	src/
D_INC :=	include/
D_OBJ :=	.obj/

D_MAT4 := mat4/
D_VEC3 := vec3/

#Files full path
SRC :=	$(addprefix $(D_SRC)$(D_MAT4), $(LST_SRC_MAT4)) \
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
