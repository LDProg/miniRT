.PHONY:	all clean fclean re

#Files
LST_SRC_MATRICE :=	matrice_init.c matrice_ops.c matrice_trsf.c

LST_SRC_VECTOR :=	tuple_cmp.c tuple_init.c tuple_ops.c vector_ops.c

LST_INC :=	libmath.h libmath_structures.h

#Directories
D_SRC :=	src/
D_INC :=	include/
D_OBJ :=	.obj/

D_MATRICE := matrice/
D_VECTOR := vector/

#Files full path
SRC :=	$(addprefix $(D_SRC)$(D_MATRICE), $(LST_SRC_MATRICE)) \
		$(addprefix $(D_SRC)$(D_VECTOR), $(LST_SRC_VECTOR))

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
