
# NAME = get.a

# SRC = get_next_line.c
# OBJ = $(SRC:.c=.o)

all:
	@gcc -Wall -Wextra -Werror main.c gnl.c gnl_utils.c -D BUFFER_SIZE=20
	@./a.out prueba.txt

size:
	@gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c gnl.c gnl_utils.c gnl.h
	@./a.out	

clean:
	@rm ./a.out
	@rm -rf a.out.dSYM
	@echo eliminaos nwn

debug:
	@gcc -Wall -Wextra -Werror main.c gnl.c gnl_utils.c -D BUFFER_SIZE=20 -g3
	@lldb -- a.out prueba.txt
re:
	make clean
	make all
	
re_debug:
	make clean
	make debug


.PHONY: all size clean debug re re_debug
