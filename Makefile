NAME = minishell

#NORMALİ
CFLAGS	:= -Wall -Werror -Wextra -I $(INCLUDE) /goinfre/homebrew/opt/readline/include
READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib
#LCFLAGS	:= -Wall -Werror -Wextra -I $(INCLUDE) /usr/include/readline
#SEFA
#CFLAGS	:= -Wall -Werror -Wextra -I $(INCLUDE) /Users/sefatunca/homebrew/opt/readline/include

#READLINE = -lreadline -L /Users/sefatunca/homebrew/opt/readline/lib
#LREADLINE = -L/usr/include -lreadline 
INCLUDE = -I ./include
SRC = $(shell find src -name "*.c")
GREEN = \033[0;32m
BLUE = \033[0;34m
DEFAULT = \033[0m
TEAL = \033[0;36m

all: $(NAME)

$(NAME):
#	@make norm
	@echo "$(GREEN)Compiling...$(DEFAULT)"
	@gcc $(CFLAGS) $(SRC) $(READLINE) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)Compiled.$(DEFAULT)"
	@echo "$(TEAL)./$(NAME)$(GREEN) is Ready to Use.$(DEFAULT)"

norm :
	@echo "$(GREEN)Norminette...$(DEFAULT)"
	@norminette src include
	@if [ $$? -eq 0 ]; then \
		echo "$(GREEN)Norminette is $(TEAL)[$(GREEN)OK$(TEAL)].$(DEFAULT)"; \
	else \
		echo "$(GREEN)Norminette is $(TEAL)[$(RED)KO$(TEAL)].$(DEFAULT)"; \
	fi
#	@echo "Norminette is $(TEAL)[$(GREEN)OK$(TEAL)].$(DEFAULT)"

clean:
	@echo "$(GREEN)Cleaning$(TEAL) Objects..."
	@echo "Done$(DEFAULT)"

fclean: clean
	@echo "$(GREEN)Cleaning$(TEAL) Executable..."
	@rm -rf $(NAME)
	@echo "Done$(DEFAULT)"

re: fclean all

.PHONY:
	all clean fclean re
