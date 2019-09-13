##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task01 of CPool Day10
##

SRC			=	src/main.c							\
				src/op.c							\
				src/flags.c							\
				src/init_info.c						\
				src/my_exit.c						\
				src/u_strcpy.c						\
				src/print_dump.c					\
				src/set_load_address.c				\
				src/read_programs.c					\
				src/set_first_register.c			\
				src/game.c							\
				src/conversions_hti.c				\
				src/take_params.c					\
				src/write_in_mem.c					\
				src/verify_pc.c						\
				src/ncurses/graphic_ncurses.c		\
				src/ncurses/ncurses_set_colors.c	\
				src/ncurses/actions_ncurses.c		\
				src/ncurses/print_info_ncurs.c		\
				src/instructions/live.c				\
				src/instructions/zjmp.c				\
				src/instructions/sti.c				\
				src/instructions/and.c				\
				src/instructions/ld.c				\
				src/instructions/add.c				\
				src/instructions/fork.c				\
				src/instructions/sub.c				\
				src/instructions/st.c				\
				src/instructions/aff.c				\
				src/instructions/or.c				\
				src/instructions/xor.c				\
				src/instructions/lfork.c			\
				src/instructions/lld.c				\
				src/instructions/ldi.c				\
				src/instructions/lldi.c				\
				src/network/online_multi.c			\
				src/network/server.c				\
				src/network/init_server.c			\
				src/network/client.c

LIB		=		lib/my/

PROJECT	=		CoreWar

NAME	=		corewar

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

	@printf "\x1B[1;34m\rCompiling CoreWar      %$(SPACES)c\x1B[1;0m" ' '
	@gcc -o $(NAME) $(SRC) -g3 -L$(LIB) -lmy -lncurses

	@rm -rf corewar.dSYM
	@printf "\x1B[1;32m\rCompilation terminated%$(SPACES)c\n\x1B[1;0m" ' '


clean:
	@rm -rf corewar.dSYM


fclean: clean
	@printf "\x1B[1;31mCleaning...\n\x1B[1;0m"
	rm -f corewar $(LIB)libmy.a


re:		fclean
	@printf "\x1B[1;33mRecompiling...\n\x1B[1;0m"
	@make -sC $(LIB)
	@gcc -o corewar $(SRC) -g3 -L$(LIB) -lmy -lncurses
	@rm -rf corewar.dSYM


auteur:
	echo "Lucas GOIFFON" > Auteur
