NAME = minishell

#CFLAGS	:= -Wall -Werror -Wextra -I $(INCLUDE) /goinfre/homebrew/opt/readline/include
LCFLAGS	:= -Wall -Werror -Wextra -I $(INCLUDE) /usr/include/readline
#READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib
LREADLINE = -L/usr/include -lreadline 
INCLUDE = -I ./include
SRC = $(shell find src -name "*.c")

all: $(NAME)
	@echo "$(NAME) is Ready"

$(NAME):
	@echo "Compiling..."
	@gcc -g $(LCFLAGS) $(SRC) $(LREADLINE) $(INCLUDE) -o $(NAME)
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
