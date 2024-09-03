flags = -Wall -Wextra -Werror -std=c++98 -g
name = 28B_not28C

all:
	@clear
	@echo Sto creando gli oggetti...
	@c++ $(flags) *.cpp -o $(name)
	@sleep 0.2
	@echo Fatto ✓

fclean:
	@clear
	@echo Sto cancellando...
	@-rm -f $(name)
	@-rm -rf Form.dSYM
	@-rm -rf home_shrubbery
	@sleep 0.4
	@echo Fatto ✓

re: fclean all