flags = -Wall -Wextra -Werror -std=c++98 -g
name = Form

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
	@sleep 0.4
	@echo Fatto ✓

re: fclean all