NAME = pipex
NAME_B = pipex_bonus

CC = cc
FLAGS = -Wall -Werror -Wextra -O3
LIBRARIES = -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

HEADERS_LIST = pipex.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_DIRECTORY_B = ./sources/
SOURCES_LIST =	arggs.c \
				awk.c \
				comand.c \
				doc.c \
				exe.c \
				file.c \
				full_p.c \
				musuko_bonus.c \
				musuko.c \
				open_f.c \
				oya.c \
				path_find.c \
				sub.c \
				the_error.c \

SOURCES_LIST_M =	pipex.c
SOURCES_LIST_B =	pipex_bonus.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
SOURCES_M = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST_M))
SOURCES_B = $(addprefix $(SOURCES_DIRECTORY_B), $(SOURCES_LIST_B))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_LIST_M = $(patsubst %.c, %.o, $(SOURCES_LIST_M))
OBJECTS_LIST_B = $(patsubst %.c, %.o, $(SOURCES_LIST_B))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))
OBJECTS_M = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_M))
OBJECTS_B = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_B))


# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all bonus clean fclean re

all: $(NAME)

#bonus: $(NAME_B)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_M)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(LIBFT) $(OBJECTS) $(OBJECTS_M) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(NAME_B): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_B)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(LIBFT) $(OBJECTS) $(OBJECTS_B) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME_B) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME_B) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@rm -f $(NAME_B)
	@echo "$(NAME): $(RED)$(NAME_B) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
