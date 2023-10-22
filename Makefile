
# NAME = get.a

# SRC = get_next_line.c
# OBJ = $(SRC:.c=.o)
#

all:
	gcc $(CFLAGS) main.c get_next_line.c get_next_line.h get_next_line_utils.c

clean:
	@rm ./a.out
	@rm get_next_line.h.gch 
	@rm -rf a.out.dSYM
	@echo eliminaos nwn

debug:
	gcc $(CFLAGS) main.c get_next_line.c get_next_line.h get_next_line_utils.c -g3
	@echo Listop
# @echo compilando nwn
# @lldb -- a.out prueba.txt

re:
	make clean
	make all

re_debug:
	make clean
	make debug

bf: CFLAGS += -D BUFFER_SIZE=$(bf)
bf: CFLAGS += -g3
bf: all

.PHONY: all size clean debug re re_debug
