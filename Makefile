NAME = minishell

CFLAGS	:= -Wall -Werror -Wextra -ggdb -I $(INCLUDE) /goinfre/homebrew/opt/readline/include
READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib
INCLUDE = -I ./include
SRC = $(shell find src -name "*.c")

all: $(NAME)
	@echo "Done"

$(NAME):
	@echo "Compiling..."
	@gcc $(CFLAGS) $(SRC) $(READLINE) $(INCLUDE) -o $(NAME)
	@make clean

clean:
	@rm -rf $(NAME).dSYM

fclean: clean
	@echo "Cleaning Program..."
	@rm -rf $(NAME)
	@echo "Done"

re: fclean all

.PHONY:
	all clean fclean re