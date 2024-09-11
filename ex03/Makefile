FLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = intern_program

all:
	@clear
	@echo Sto creando gli oggetti...
	@c++ $(FLAGS) *.cpp -o $(NAME)
	@sleep 0.2
	@echo Done ✓

fclean:
	@clear
	@echo Sto cancellando...
	@-rm -f $(NAME)
	@-rm -rf Garden_shrubbery
	@sleep 0.4
	@echo Done ✓

re: fclean all