##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Task01 of CPool Day10
##

SRC_ASM		=	asm/src/main.c								\
				asm/src/op.c								\
				asm/src/linked_lists.c						\
				asm/src/insertion_ll.c						\
				asm/src/stwa_for_asm.c						\
				asm/src/header.c							\
				asm/src/stock.c								\
				asm/src/my_exit.c							\
				asm/src/get_parameters.c					\
				asm/src/mnemonics.c							\
				asm/src/call_labels.c						\
				asm/src/manage_indexs.c						\
				asm/src/write_in_file.c						\
				asm/src/badchars_labels.c					\
				asm/src/is_same_labels.c

SRC_COR		=	corewar/src/main.c							\
				corewar/src/op.c							\
				corewar/src/flags.c							\
				corewar/src/init_info.c						\
				corewar/src/my_exit.c						\
				corewar/src/u_strcpy.c						\
				corewar/src/print_dump.c					\
				corewar/src/set_load_address.c				\
				corewar/src/read_programs.c					\
				corewar/src/set_first_register.c			\
				corewar/src/game.c							\
				corewar/src/conversions_hti.c				\
				corewar/src/take_params.c					\
				corewar/src/write_in_mem.c					\
				corewar/src/verify_pc.c						\
				corewar/src/ncurses/graphic_ncurses.c		\
				corewar/src/ncurses/ncurses_set_colors.c	\
				corewar/src/ncurses/actions_ncurses.c		\
				corewar/src/ncurses/print_info_ncurs.c		\
				corewar/src/instructions/live.c				\
				corewar/src/instructions/zjmp.c				\
				corewar/src/instructions/sti.c				\
				corewar/src/instructions/and.c				\
				corewar/src/instructions/ld.c				\
				corewar/src/instructions/add.c				\
				corewar/src/instructions/fork.c				\
				corewar/src/instructions/sub.c				\
				corewar/src/instructions/st.c				\
				corewar/src/instructions/aff.c				\
				corewar/src/instructions/or.c				\
				corewar/src/instructions/xor.c				\
				corewar/src/instructions/lfork.c			\
				corewar/src/instructions/lld.c				\
				corewar/src/instructions/ldi.c				\
				corewar/src/instructions/lldi.c

LIB		=		lib/my/

PROJECT	=		CoreWar

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

	@printf "\x1B[1;34m\rCompiling ASM          %$(SPACES)c\x1B[1;0m" ' '
	@gcc -o asm/asm $(SRC_ASM) -g3 -L$(LIB) -lmy

	@printf "\x1B[1;34m\rCompiling CoreWar      %$(SPACES)c\x1B[1;0m" ' '
	@gcc -o corewar/corewar $(SRC_COR) -g3 -L$(LIB) -lmy -lncurses

	@rm -rf asm/asm.dSYM
	@rm -rf corewar/corewar.dSYM
	@printf "\x1B[1;32m\rCompilation terminated%$(SPACES)c\n\x1B[1;0m" ' '


clean:
	@rm -rf asm/asm.dSYM
	@rm -rf corewar/corewar.dSYM


fclean: clean
	@printf "\x1B[1;31mCleaning...\n\x1B[1;0m"
	rm -f asm/asm corewar/corewar $(LIB)libmy.a


re:		fclean
	@printf "\x1B[1;33mRecompiling...\n\x1B[1;0m"
	@make -sC $(LIB)
	@gcc -o asm/asm $(SRC_ASM) -g3 -L$(LIB) -lmy
	@gcc -o corewar/corewar $(SRC_COR) -g3 -L$(LIB) -lmy -lncurses
	@rm -rf asm/asm.dSYM
	@rm -rf corewar/corewar.dSYM


auteur:
	echo "Lucas GOIFFON" > Auteur
