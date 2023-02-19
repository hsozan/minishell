NAME = minishell

CFLAGS	:= -Wall -Werror -Wextra -I $(INCLUDE) /goinfre/homebrew/opt/readline/include
#LCFLAGS	:= -Wall -Werror -Wextra -I $(INCLUDE) /usr/include/readline
READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib
#LREADLINE = -L/usr/include -lreadline 
INCLUDE = -I ./include
SRC = $(shell find src -name "*.c")
GREEN = \033[0;32m
BLUE = \033[0;34m
DEFAULT = \033[0m

all: $(NAME)
	@echo "$(BLUE)./$(NAME)$(GREEN) is Ready to Use.$(DEFAULT)"

$(NAME):
	@echo "$(GREEN)Compiling...$(DEFAULT)"
	@gcc $(CFLAGS) $(SRC) $(READLINE) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)Done$(DEFAULT)"

clean:
	@echo "$(GREEN)Cleaning$(BLUE) Objects..."
	@echo "Done$(DEFAULT)"

fclean: clean
	@echo "$(GREEN)Cleaning$(BLUE) Executable..."
	@rm -rf $(NAME)
	@echo "Done$(DEFAULT)"

re: fclean all

.PHONY:
	all clean fclean re
