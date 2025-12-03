.PHONY:	all clean fclean re

#Files
LST_SRC :=	tuple_init.c tuple_cmp.c tuple_ops.c vector_ops.c

#Directories
D_SRC :=	src/
D_INC :=	include/
D_OBJ :=	.obj/

#Files full path
SRC :=	$(addprefix $(D_SRC), $(LST_SRC))

OBJ :=	$(subst $(D_SRC), $(D_OBJ), $(SRC:.c=.o))

DEPSFILES :=	$(subst $(D_SRC), $(D_OBJ), $(SRC:.o=.d))

#Variables
NAME :=	libvector.a
CC :=	cc
C_FLAGS :=	-Wall -Wextra -Werror -O3

RM :=	rm -rf

#Rules
-include $(DEPSFILES)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

$(D_OBJ)%.o: $(D_SRC)%.c Makefile | $(D_OBJ)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(D_INC) -MMD -MP -c $< -o $@

$(D_OBJ):
	@mkdir -p $@

clean:
	@$(RM) $(D_OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean $(NAME)
