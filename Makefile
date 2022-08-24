.PHONY: all clean fclean re cleanb fcleanb reb

CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror
RL_FLAG		=	-lreadline

SUPP_FILES	=	readline.supp add_history.supp
SUPP_PRFX	=	--suppressions=./supps
SUPP_SRC	=	$(addprefix $(SUPP_PRFX)/, $(SUPP_FILES))
VALGRIND	=	valgrind --track-origins=yes --leak-check=full \
				--show-leak-kinds=all --track-fds=yes
VALGRIND	+=	$(SUPP_SRC)

LIBFT		=	libs/libft/libft.a

NAME		=	minishell
SRC_DIR		=	src
OBJ_DIR		=	objects
HEADER		=	$(SRC_DIR)/mini_shell.h

NAME_BONUS	=	checker
SRC_DIR_B	=	src_bonus
OBJ_DIR_B	=	objects_bonus
HEADER_B	=	$(SRC_DIR_B)/checker.h

SRC_FILES	=	mini_shell.c \

SRC_FILES	+=	utils/exec_builtin.c \
				utils/create_list.c \
				utils/execute.c\
				utils/refresh_prompt.c \
				utils/signal.c \
				utils/find_cmd_path.c \
				utils/exec_external.c \
				utils/free_cmds.c \
				utils/parse_cmds.c \
				utils/parse_line.c \
				utils/parse_chars.c \
				utils/check_error.c \
				utils/open_file.c

SRC_FILES	+=	builtins/echo.c \
				builtins/cd.c \
				builtins/pwd.c \
				builtins/export.c \
				builtins/unset.c \
				builtins/env.c \
				builtins/msh_exit.c

# SRC_FILES_B	=

SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_BONUS	=	$(addprefix $(SRC_DIR_B)/, $(SRC_FILES_B))
OBJ_BONUS	=	$(SRC_BONUS:$(SRC_DIR_B)/%.c=$(OBJ_DIR_B)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_B)/%.o: $(SRC_DIR_B)/%.c
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
	$(VALGRIND) ./$(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_DIR_B) $(OBJ_BONUS) $(HEADER_B)
	@make -C ./libs/libft
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBFT)

$(OBJ_DIR_B):
	mkdir -p $(OBJ_DIR_B)/utils
	mkdir -p $(OBJ_DIR_B)/operations

cleanb:
	@rm -rf $(OBJ_DIR_B)

fcleanb:
	@make cleanb
	@find -name '$(NAME_BONUS)' -delete

reb:
	@make fcleanb && make $(NAME_BONUS)

testb: $(NAME) $(NAME_BONUS)
	./$(NAME) $(TEST_LIST) | ./$(NAME_BONUS) $(TEST_LIST)
