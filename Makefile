.PHONY: all clean fclean re

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
RL_FLAG = -lreadline

VALGRIND = valgrind --suppressions=./local.supp --leak-check=full
LIBFT = libs/libft/libft.a

NAME = mini_shell
SRC_DIR = src
OBJ_DIR = objects
HEADER = $(SRC_DIR)/mini_shell.h

NAME_BONUS = checker
SRC_DIR_BONUS = src_bonus
OBJ_DIR_BONUS = objects_bonus
HEADER_BONUS = $(SRC_DIR_BONUS)/checker.h

SRC_FILES	=	mini_shell.c \
				is_builtin.c \
				exec_builtin.c \
				execute.c

SRC_FILES	+=	builtins/echo.c \
				builtins/pwd.c \
				builtins/cd.c \

SRC_FILES_B	=	checker.c \

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_B))
OBJ_BONUS = $(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	@make -C ./libs/libft
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(RL_FLAG)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/utils
	mkdir -p $(OBJ_DIR)/builtins

clean:
	rm -rf objects objects_bonus

fclean:
	make  clean
	find -name '$(NAME)' -delete
	find -name '$(NAME_BONUS)' -delete

re:
	@make fclean && make all

test: all
	./$(NAME) $(TEST_LIST)

val: all
	make re
	$(VALGRIND) ./$(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_DIR_BONUS) $(OBJ_BONUS) $(HEADER_BONUS)
	@make -C ./libs/libft
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBFT)

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)/utils
	mkdir -p $(OBJ_DIR_BONUS)/operations

cleanb:
	@rm -rf $(OBJ_DIR_BONUS)

fcleanb:
	@make cleanb
	@find -name '$(NAME_BONUS)' -delete

reb:
	@make fcleanb && make $(NAME_BONUS)

testb: $(NAME) $(NAME_BONUS)
	./$(NAME) $(TEST_LIST) | ./$(NAME_BONUS) $(TEST_LIST)
