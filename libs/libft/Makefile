# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 14:24:44 by ebonutto          #+#    #+#              #
#    Updated: 2025/04/02 11:49:43 by maecarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
AR = ar rcs

SRC_PATH = src/
OBJ_PATH = obj/
INCLUDE = -I include/

SRC_BINARY_TREE = ft_btree_create_node.c \
				  ft_btree_apply_prefix.c \
				  ft_btree_apply_infix.c \
				  ft_btree_apply_suffix.c \
				  ft_btree_insert_data.c \
				  ft_btree_search_item.c \
				  ft_btree_level_count.c

SRCS_BINARY_TREE = $(addprefix binary_tree/, $(SRC_BINARY_TREE))
OBJS_BINARY_TREE = $(addprefix binary_tree/, $(SRC_BINARY_TREE:.c=.o))

SRC_CHAR = ft_char_charset.c \
		   ft_char_occurence.c \
		   ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_isprint.c \
		   ft_issign.c \
		   ft_isspace.c \
		   ft_tolower.c \
		   ft_toupper.c

SRCS_CHAR = $(addprefix char/, $(SRC_CHAR))
OBJS_CHAR = $(addprefix char/, $(SRC_CHAR:.c=.o))

SRC_DOUBLE_LINKED_LIST = dll_add_back.c \
						 dll_clear.c \
						 dll_insert.c \
						 dll_new.c \
						 dll_size_between.c \
						 dll_size.c

SRCS_DOUBLE_LINKED_LIST = $(addprefix double_linked_list/, $(SRC_DOUBLE_LINKED_LIST))
OBJS_DOUBLE_LINKED_LIST = $(addprefix double_linked_list/, $(SRC_DOUBLE_LINKED_LIST:.c=.o))

SRC_FD = ft_putchar_fd.c \
		 ft_putendl_fd.c \
		 ft_putnbr_fd.c \
		 ft_putstr_fd.c

SRCS_FD = $(addprefix fd/, $(SRC_FD))
OBJS_FD = $(addprefix fd/, $(SRC_FD:.c=.o))

SRC_INT = ft_atoi.c \
		  ft_itoa.c \
		  ft_swapi.c

SRCS_INT = $(addprefix int/, $(SRC_INT))
OBJS_INT = $(addprefix int/, $(SRC_INT:.c=.o))


SRC_FLOAT = ft_atod.c

SRCS_FLOAT = $(addprefix float/, $(SRC_FLOAT))
OBJS_FLOAT = $(addprefix float/, $(SRC_FLOAT:.c=.o))

SRC_LINKED_LIST = ft_lstadd_back.c \
				  ft_lstadd_front.c \
				  ft_lstclear.c \
				  ft_lstdelone.c \
				  ft_lstiter.c \
				  ft_lstlast.c \
				  ft_lstmap.c \
				  ft_lstnew.c \
				  ft_lstsize.c

SRCS_LINKED_LIST = $(addprefix linked_list/, $(SRC_LINKED_LIST))
OBJS_LINKED_LIST = $(addprefix linked_list/, $(SRC_LINKED_LIST:.c=.o))


SRC_LONG = ft_atol.c \
		   ft_islong.c

SRCS_LONG = $(addprefix long/, $(SRC_LONG))
OBJS_LONG = $(addprefix long/, $(SRC_LONG:.c=.o))

SRC_MY_MATH = ft_abs.c \
		   ft_max.c \
		   ft_min.c

SRCS_MY_MATH = $(addprefix my_math/, $(SRC_MY_MATH))
OBJS_MY_MATH = $(addprefix my_math/, $(SRC_MY_MATH:.c=.o))


SRC_MEMORY = ft_bzero.c \
			 ft_calloc.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_memset.c

SRCS_MEMORY = $(addprefix memory/, $(SRC_MEMORY))
OBJS_MEMORY = $(addprefix memory/, $(SRC_MEMORY:.c=.o))

SRC_SAFE = ft_close.c \
		   ft_dfree.c \
		   ft_error.c \
		   ft_perror.c \
		   ft_sfree.c

SRCS_SAFE = $(addprefix safe/, $(SRC_SAFE))
OBJS_SAFE = $(addprefix safe/, $(SRC_SAFE:.c=.o))

SRC_STRING = ft_str_charset.c \
			 ft_strchr.c \
			 ft_strcmp.c \
			 ft_strcpy.c \
			 ft_strdup.c \
			 ft_striteri.c \
			 ft_strjoin.c \
			 ft_strlcat.c \
			 ft_strlcpy.c \
			 ft_strlen.c \
			 ft_strmapi.c \
			 ft_strncmp.c \
			 ft_strnstr.c \
			 ft_strrchr.c \
			 ft_strtrim.c \
			 ft_substr.c

SRCS_STRING = $(addprefix string/, $(SRC_STRING))
OBJS_STRING = $(addprefix string/, $(SRC_STRING:.c=.o))

SRC_TAB = ft_split_charset.c \
		  ft_split.c \
		  ft_tabdup.c

SRCS_TAB = $(addprefix tab/, $(SRC_TAB))
OBJS_TAB = $(addprefix tab/, $(SRC_TAB:.c=.o))

SRC_TUPLE = creation/new_neg_tuple.c \
			creation/new_point.c \
			creation/new_tuple_ptr.c \
			creation/new_tuple.c \
			creation/new_vec.c \
			operations/add_tuples.c \
			operations/cross_tuples.c \
			operations/div_tuple.c \
			operations/mag_tuple.c \
			operations/mul_tuple.c \
			operations/normalize_tuple.c \
			operations/sub_tuples.c \
			utils/equal_tuples.c \
			utils/print_tuple.c

SRCS_TUPLE = $(addprefix tuple/, $(SRC_TUPLE))
OBJS_TUPLE = $(addprefix tuple/, $(SRC_TUPLE:.c=.o))

SRC_MATRIX = creation/matrix_new.c \
			 operations/matrix_cofactor.c \
			 operations/matrix_determinant.c \
			 operations/matrix_identity.c \
			 operations/matrix_inverse.c \
			 operations/matrix_minor.c \
			 operations/matrix_multiply.c \
			 operations/matrix_multiply_tuple.c \
			 operations/rotation_matrix.c \
			 operations/matrix_scale.c \
			 operations/matrix_shear.c \
			 operations/matrix_submatrix.c \
			 operations/matrix_translate.c \
			 operations/matrix_transpose.c \
			 utils/matrix_free.c \
			 utils/matrix_print.c \
			 utils/matrix_equal.c

SRCS_MATRIX = $(addprefix matrix/, $(SRC_MATRIX))
OBJS_MATRIX = $(addprefix matrix/, $(SRC_MATRIX:.c=.o))

SRC = $(addprefix $(SRC_PATH), $(SRCS_BINARY_TREE) $(SRCS_CHAR) $(SRCS_DOUBLE_LINKED_LIST) $(SRCS_FD) $(SRCS_INT) $(SRCS_FLOAT) $(SRCS_LINKED_LIST) $(SRCS_LONG) $(SRCS_MY_MATH) $(SRCS_MEMORY) $(SRCS_SAFE) $(SRCS_STRING) $(SRCS_TAB) $(SRCS_TUPLE) $(SRCS_MATRIX))
OBJ = $(addprefix $(OBJ_PATH), $(OBJS_BINARY_TREE) $(OBJS_CHAR) $(OBJS_DOUBLE_LINKED_LIST) $(OBJS_FD) $(OBJS_INT) $(OBJS_FLOAT) $(OBJS_LINKED_LIST) $(OBJS_LONG) $(OBJS_MY_MATH) $(OBJS_MEMORY) $(OBJS_SAFE) $(OBJS_STRING) $(OBJS_TAB) $(OBJS_TUPLE) $(OBJS_MATRIX))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@echo "Compiling " $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME): $(OBJ)
	$(AR) $@ $^

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
