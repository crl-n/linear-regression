PURPLE := $(shell tput setaf 5)
RESET := $(shell tput sgr0)

NAME := lib_linear_reg.so
CFLAGS := -Wall -Wextra -Werror
INCL := -I./lib_linear_reg/includes

SRC_DIR := ./lib_linear_reg/srcs
SRC := $(SRC_DIR)/train.c

OBJ_DIR := ./lib_linear_reg/obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: pre_build $(NAME)

debug: CFLAGS += -g
debug: re
no_flags: CFLAGS = -w -g
no_flags: re
asan: CFLAGS = -fsanitize=address -g
asan: re

pre_build:
	$(info $(PURPLE)Compiling library...$(RESET))

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) -fPIC -shared $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCL) -c $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
