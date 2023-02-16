NAME = minishell

CFLAGS	:= -Wall -Werror -Wextra -I $(INCLUDE) /goinfre/homebrew/opt/readline/include
READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib
INCLUDE = -I ./include
SRC = $(shell find src -name "*.c")

all: $(NAME)
	@echo "Done"

$(NAME):
	@echo "Compiling..."
	@gcc -g $(CFLAGS) $(SRC) $(READLINE) $(INCLUDE) -o $(NAME)
	@make clean

clean:
	@echo "Cleaning Objects..."
	@echo "Done"

fclean: clean
	@echo "Cleaning Program..."
	@rm -rf $(NAME)
	@echo "Done"

re: fclean all

.PHONY:
	all clean fclean re