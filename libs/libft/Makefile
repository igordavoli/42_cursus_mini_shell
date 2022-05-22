.PHONY: all tests_run clean fclean re

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

SRC_DIR = src
OBJ_DIR = objects
HEADER = $(SRC_DIR)/libft.h

# STRING
SRC_FILES	=	str/ft_strlcat.c \
				str/ft_strlcpy.c \
				str/ft_striteri.c \
				str/ft_strrchr.c \
				str/ft_strdup.c \
				str/ft_strlen.c \
				str/ft_substr.c \
				str/ft_strtrim.c \
				str/ft_strjoin2.c \
				str/ft_strncmp.c \
				str/ft_strjoin.c \
				str/ft_strnstr.c \
				str/ft_strchr.c \
				str/ft_split.c \
				str/ft_strmapi.c

#  FT_SPLIT2
SRC_FILES	+=	str/ft_split2/utils/ft_get_wrd_size.c \
				str/ft_split2/utils/ft_count_aps.c \
				str/ft_split2/utils/ft_treat_str_aps.c \
				str/ft_split2/utils/ft_get_wrd.c \
				str/ft_split2/utils/ft_wrd_cnt.c \
				str/ft_split2/ft_split2.c

#CHARS
SRC_FILES	+=	ft_isdigit.c \
				ft_isascii.c \
				ft_isspace.c \
				ft_isprint.c \
				ft_isalpha.c \
				ft_isalnum.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_itoa.c \
				ft_atoi.c \
				ft_atol.c \
				ft_bubble_sort.c
# MEMORY
SRC_FILES	+=	mem/ft_memcmp.c \
				mem/ft_memchr.c \
				mem/ft_memmove.c \
				mem/ft_memcpy.c \
				mem/ft_memset.c \
				mem/ft_bzero.c \
				mem/ft_calloc.c \
				mem/ft_free_ptr.c \
				mem/ft_free_ptrs.c

# LINKED-LIST
SRC_FILES	+=	lkd_lst/ft_lstmap.c \
				lkd_lst/ft_lstdelone.c \
				lkd_lst/ft_lstadd_back.c \
				lkd_lst/ft_lstsize.c \
				lkd_lst/ft_lstnew.c \
				lkd_lst/ft_lstiter.c \
				lkd_lst/ft_lstlast.c \
				lkd_lst/ft_lstclear.c \
				lkd_lst/ft_lstadd_front.c

# DUBLE_LINKED-LIST
SRC_FILES	+=	d_lkd_lst/ft_dlstmap.c \
				d_lkd_lst/ft_dlstdelone.c \
				d_lkd_lst/ft_dlstadd_back.c \
				d_lkd_lst/ft_dlstadd_front.c \
				d_lkd_lst/ft_dlstsize.c \
				d_lkd_lst/ft_dlstnew.c \
				d_lkd_lst/ft_dlstiter.c \
				d_lkd_lst/ft_dlstlast.c \
				d_lkd_lst/ft_dlstfirst.c \
				d_lkd_lst/ft_dlstclear.c

# CIRCULAR-DUBLE_LINKED-LIST
SRC_FILES	+=	cir_d_lkd_lst/ft_cir_dlstadd_back.c \
				cir_d_lkd_lst/ft_cir_dlstadd_front.c \
				cir_d_lkd_lst/ft_cir_dlstiter.c \
				cir_d_lkd_lst/ft_cir_dlstmap.c \
				cir_d_lkd_lst/ft_cir_dlstnew.c \
				cir_d_lkd_lst/ft_cir_dlstsize.c

# READ AND WRITE
SRC_FILES	+=	rw/ft_putendl_fd.c \
				rw/ft_putnbr_fd.c \
				rw/ft_putchar_fd.c \
				rw/ft_putstr_fd.c \
				rw/get_next_line.c \
				rw/ft_load_file.c

# FT_PRINTF
SRC_FILES	+=	rw/ft_printf/ft_printf.c \
				rw/ft_printf/ft_resolve_dec.c \
				rw/ft_printf/ft_resolve_chr.c \
				rw/ft_printf/ft_resolve_str.c \
				rw/ft_printf/ft_resolve_flg.c \
				rw/ft_printf/ft_resolve_ptr.c \
				rw/ft_printf/ft_resolve_uns.c \
				rw/ft_printf/ft_resolve_hex.c \
				rw/ft_printf/ft_printf_puts.c \
				rw/ft_printf/ft_printf_utils.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p objects/mem
	mkdir -p objects/lkd_lst
	mkdir -p objects/d_lkd_lst
	mkdir -p objects/cir_d_lkd_lst
	mkdir -p objects/rw/ft_printf
	mkdir -p objects/str/ft_split2/utils

bonus: $(OBJ_B)
	ar rcs $(NAME) $(OBJ_B)

clean:
	@rm -rf objects

fclean:
	make clean
	@rm -rf $(NAME)
re:
	make fclean && make all

