##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task01 of CPool Day10
##

SRC			=	src/main.c							\
				src/op.c							\
				src/read_create_file.c				\
				src/tools.c							\
				src/write_instructions.c

LIB		=		lib/my/

PROJECT	=		Desassembler

NAME	=		desasm

SPACES	=		$(shell expr '$(PROJECT)' : '.*')

all:
	@printf "\x1B[1;33mWelcome to $(PROJECT) Project !\x1B[1;0m"
	@sleep 0.5

ifeq ($(shell test -f $(LIB)libmy.a ; echo $$?), 1)
	@printf "\x1B[1;34m\rCompiling my lib       %$(SPACES)c\x1B[1;0m" ' '
	@make -sC $(LIB)
else
	@printf "\x1B[1;31m\rLib already exist      %$(SPACES)c\x1B[1;0m" ' '
	@sleep 0.5
endif

	@printf "\x1B[1;34m\rCompiling $(PROJECT)      %$(SPACES)c\x1B[1;0m" ' '
	@gcc -o $(NAME) $(SRC) -g3 -L$(LIB) -lmy

	@rm -rf desasm.dSYM
	@printf "\x1B[1;32m\rCompilation terminated%$(SPACES)c\n\x1B[1;0m" ' '


clean:
	@rm -rf desasm.dSYM


fclean: clean
	@printf "\x1B[1;31mCleaning...\n\x1B[1;0m"
	rm -f $(NAME) $(LIB)libmy.a


re:		fclean
	@printf "\x1B[1;33mRecompiling...\n\x1B[1;0m"
	@make -sC $(LIB)
	@gcc -o $(NAME) $(SRC) -g3 -L$(LIB) -lmy
	@rm -rf desasm.dSYM


auteur:
	echo "Lucas GOIFFON" > Auteur
