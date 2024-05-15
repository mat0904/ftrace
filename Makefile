##
## EPITECH PROJECT, 2023
## mat
## File description:
## Makefile
##

MAIN_SRC	=	src/main.c

FILE_SRC	=	$(shell find src/ -type f -name "*.c" -not -name "main.c")

TEST_SRC	=	tests/is_working.c \

FILE_OBJ	=	$(FILE_SRC:.c=.o)
MAIN_OBJ	=	$(MAIN_SRC:.c=.o)
TEST_OBJ	=	$(TEST_SRC:.c=_test.o)

FILE_GCDA	=	$(FILE_SRC:.c=.gcda)
FILE_GCNO	=	$(FILE_SRC:.c=.gcno)

CC	=	gcc

DEBUG	=	-g3
SANITIZE	=	-fsanitize=address,undefined \
-fsanitize-recover=address,undefined
INCLUDE	=	-Iinclude
NO_UNUSED	=	-Wno-unused-parameter -Wno-unused-function
CFLAGS	= -Wall -Wextra -Iinclude -std=c17 \
		  $(NO_UNUSED)

LIB	=
LD_PRELOAD	=
LDFLAGS	=	$(LIB) -Llib -lqueue

COVERAGE	=	--coverage -lcriterion

EXE	=	ftrace
TEST_EXE	=	$(EXE)_test

all:	$(EXE)

%.o:	%.c
	$(CC) -o $@ -c $< $(CFLAGS)

%_test.o:	%.c
	$(CC) -o $@ -c $<

$(EXE):	$(FILE_OBJ) $(MAIN_OBJ)
	@make -C lib --no-print-dir
	$(CC) -o $(EXE) $(FILE_OBJ) $(MAIN_OBJ) $(LD_PRELOAD) $(LDFLAGS)

debug:	CFLAGS += $(DEBUG)
debug:	$(FILE_OBJ) $(MAIN_OBJ) $(EXE)

redebug: fclean debug

sanitize: CFLAGS += $(DEBUG) $(SANITIZE)
sanitize: LD_PRELOAD = -lasan -lubsan
sanitize: $(FILE_OBJ) $(MAIN_OBJ) $(EXE)

resanitize: fclean sanitize

clean:
	@make -C lib clean --no-print-dir
	rm -rf $(MAIN_OBJ) $(TEST_OBJ) $(FILE_OBJ)
	rm -rf $(FILE_GCDA) $(FILE_GCNO)
	rm -rf coding-style-reports.log
	$(shell find * -name "vgcore.*" -delete)

fclean:	clean
	@make -C lib fclean --no-print-dir
	rm -rf $(EXE)
	rm -rf $(TEST_EXE)

re:	fclean all

unit_tests:	CFLAGS += $(COVERAGE)
unit_tests: LDFLAGS += $(COVERAGE)
unit_tests: $(FILE_OBJ) $(TEST_OBJ)
	$(CC) -o $(EXE) $(FILE_OBJ) $(TEST_OBJ) $(LDFLAGS)

tests_run:	clean unit_tests
	./$(TEST_EXE)

.PHONY: all clean re fclean debug unit_tests tests_run redebug sanitize
.PHONY: resanitize
