NAME = mathvect.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INC =	mmathvect.h			\

OBJDIR =	.obj

SRC = 	add_vect_point.c init_tuple.c sub_point_vect.c sub_points.c

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	ar rcs $(NAME) $(LIB) $?

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

%.o : %.c Makefile $(INC) $(LIB)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# .print_header:
# 	$(call DISPLAY_TITLE)

.PHONY: all fclean re


# ########################################################################################################################
# #                                                       COLORS                                                         #
# ########################################################################################################################

# DEF_COLOR 	= \033[0;39m
# GREEN		= \033[1;92m
# BLUE		= \033[0;94m

# ########################################################################################################################
# #                                                       DISPLAY                                                        #
# ########################################################################################################################

# define DISPLAY_TITLE
# 						@echo "$(BLUE) __      ________ _____ _______ _      _____ ____"
# 						@echo " \ \    / /  ____/ ____|__   __| |    |_   _|  _ \\"
# 						@echo "  \ \  / /| |__ | |       | |  | |      | | | |_| |"
# 						@echo "   \ \/ / |  __|| |       | |  | |      | | |  _ <"
# 						@echo "    \  /  | |___| |____   | |  | |____ _| |_| |_| |"
# 						@echo "     \/   |______\_____|  |_|  |______|_____|____/ "
# 						@echo "$(GREEN)                                        by gaducurt$(DEF_COLOR)"
# 						@printf "\n"
# endef
