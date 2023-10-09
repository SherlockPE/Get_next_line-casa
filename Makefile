
# NAME = get.a

# SRC = get_next_line.c
# OBJ = $(SRC:.c=.o)

all:
	gcc -Wall -Wextra -Werror main.c get_next_line.c get_next_line.h
	@./a.out

size:
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line.h
	@./a.out	

clean:
	@rm ./a.out
	@echo eliminao nwn

# all:
# 	@gcc -Wall -Wextra -Werror macros.c
# 	@./a.out

# size:
# 	@gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 macros.c
# 	@./a.out
	

# clean:
# 	@rm ./a.out
# 	@echo eliminao nwn