
# NAME = get.a

# SRC = get_next_line.c
# OBJ = $(SRC:.c=.o)

all:
	@gcc main.c get_next_line.c get_next_line.h get_next_line_utils.c
	@./a.out prueba.txt

size:
	@gcc main.c get_next_line.c get_next_line.h get_next_line_utils.c
	@echo compilando nwn
	@./a.out	

clean:
	@rm ./a.out
	@rm get_next_line.h.gch 
	@rm -rf a.out.dSYM
	@echo eliminaos nwn

debug:
	@gcc main.c get_next_line.c get_next_line.h get_next_line_utils.c -g3
	@echo Listop
# @echo compilando nwn
# @lldb -- a.out prueba.txt

re:
	make clean
	make all

re_debug:
	make clean
	make debug

.PHONY: all size clean debug re re_debug
