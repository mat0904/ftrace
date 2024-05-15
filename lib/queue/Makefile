##
## EPITECH PROJECT, 2024
## myteams
## File description:
## Makefile
##

FILE_SRC    =	src/at_queue.c \
				src/back.c \
				src/foreach.c \
				src/create_node.c \
				src/front.c \
				src/get.c \
				src/insert.c \
				src/push_back.c \
				src/push_front.c \
				src/size.c \
				src/in_queue.c \
				src/remove.c \
				src/queue/create_queue.c \
				src/queue/delete_queue.c

FILE_OBJ    =    $(FILE_SRC:.c=.o)

CC    =    gcc

DEBUG	=	-g3 -DDEBUG
INCLUDE	=	-Iinclude -I../include
NO_UNUSED	=	-Wno-unused-parameter -Wno-unused-function
CFLAGS    = -Wall -Wextra -ansi -pedantic \
			$(NO_UNUSED) $(INCLUDE)

OUTPUT_DIR	=	..
EXE    =    ../libqueue.a

all:    $(EXE)

%.o:	%.c
	$(CC) $(CFLAGS)   -c -o $@ $<

$(EXE):	$(FILE_OBJ)
	ar rc $(EXE) $(FILE_OBJ)

debug:	CFLAGS += $(DEBUG)
debug:	$(FILE_OBJ)
	ar rc $(EXE) $(FILE_OBJ)

clean:
	rm -rf $(FILE_OBJ)

fclean:	clean
	rm -rf $(EXE)

re:    fclean all

unit_tests:	CFLAGS += $(COVERAGE) -DTEST
unit_tests: LDFLAGS += $(COVERAGE)
unit_tests: $(FILE_OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST_EXE) $^ $(LDFLAGS)

tests_run:    clean unit_tests
	./$(TEST_EXE) --jobs 1

.PHONY: all clean re fclean unit_tests tests_run
