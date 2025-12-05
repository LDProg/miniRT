NAME = mathvect.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

INC =	mathvect.h			\

OBJDIR =	.obj

SRC = 	vector/add_vect_point.c vector/init_tuple.c vector/sub_point_vect.c vector/sub_two_points.c \
		vector/sub_two_vect.c vector/inv_tup.c vector/scalar_mult.c vector/scalar_div.c  vector/vect_mag.c \
		vector/normalize_vect.c vector/dot_product.c vector/cross_product.c matrix/translate_matrix.c \
		matrix/all_rotate_matrix.c matrix/rotate_x.c matrix/rotate_y.c matrix/rotate_z.c matrix/scaling_matrix.c \

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re

