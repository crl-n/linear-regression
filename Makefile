PURPLE := $(shell tput setaf 5)
RESET := $(shell tput sgr0)

NAME := lib_linear_reg.so
CPROGRAM := regress
CFLAGS := -Wall -Wextra -Werror
INCL := -I./lib_linear_reg/includes

SRC_DIR := ./lib_linear_reg/srcs
SRC := $(SRC_DIR)/fit.c
SRC += $(SRC_DIR)/matrix.c
SRC += $(SRC_DIR)/matrix_multiplication.c
SRC += $(SRC_DIR)/gradient_descent.c
SRC += $(SRC_DIR)/gradient.c
SRC += $(SRC_DIR)/predict.c
SRC += $(SRC_DIR)/performance.c
SRC += $(SRC_DIR)/r2_score.c
SRC += $(SRC_DIR)/mean_squared_error.c
SRC += $(SRC_DIR)/python_api.c
SRC += $(SRC_DIR)/memdup.c

OBJ_DIR := ./lib_linear_reg/obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: pre_build_library $(NAME) pre_build_cprogram $(CPROGRAM)

debug: CFLAGS += -g
debug: re
no_flags: CFLAGS = -w -g
no_flags: re
asan: CFLAGS = -fsanitize=address -g
asan: re

pre_build_library:
	$(info $(PURPLE)Compiling library...$(RESET))

pre_build_cprogram:
	$(info $(PURPLE)Compiling main C program...$(RESET))

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) -fPIC -shared $(CFLAGS) $(OBJ) -o $@

$(CPROGRAM): $(OBJ_DIR) $(OBJ)
	$(CC) main.c $(CFLAGS) $(NAME) $(INCL) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCL) -c $^ -o $@

clean:
	$(info $(PURPLE)Removing object files...$(RESET))
	rm -rf $(OBJ_DIR)

fclean: clean
	$(info $(PURPLE)Removing executable and library...$(RESET))
	rm -rf $(NAME)
	rm -rf $(CPROGRAM)

re: fclean all

.PHONY: all clean fclean re
