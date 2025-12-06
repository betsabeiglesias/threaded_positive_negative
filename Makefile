NAME = nemergent

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

SRCS = main.c \
		check_args.c \
		aux.c \
		threads.c \
		routine.c \
		sort.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g3
INCLUDES = -I$(INC_DIR)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) *.log

fclean: clean
	@$(RM) $(NAME)

re: fclean all


# Testing
VALGRIND_THREADS ?= 2
VALGRIND_NUMBERS ?= 42

test: $(NAME)
	@./$(NAME) $(VALGRIND_THREADS) $(VALGRIND_NUMBERS)

valgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	          --log-file=valgrind.log ./$(NAME) $(VALGRIND_THREADS) $(VALGRIND_NUMBERS)
	@cat valgrind.log

helgrind: $(NAME)
	@valgrind --tool=helgrind -s --log-file=helgrind.log \
	          ./$(NAME) $(VALGRIND_THREADS) $(VALGRIND_NUMBERS)
	@cat helgrind.log

.PHONY: all clean fclean re valgrind helgrind


