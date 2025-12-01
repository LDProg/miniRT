NAME = matrixlib.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilibs/mathvect/

INC =	matrixlib.h			\

OBJDIR =	.obj

SRC = 	translate_matrix.c

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