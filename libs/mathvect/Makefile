NAME = mathvect.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INC =	mathvect.h			\

OBJDIR =	.obj

SRC = 	add_vect_point.c init_tuple.c sub_point_vect.c sub_two_points.c \
		sub_two_vect.c inv_tup.c scalar_mult.c scalar_div.c  vect_mag.c \
		normalize_vect.c dot_product.c cross_product.c translate_matrix.c \
		all_rotate_matrix.c rotate_x.c rotate_y.c rotate_z.c

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

%.o : %.c Makefile $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re

