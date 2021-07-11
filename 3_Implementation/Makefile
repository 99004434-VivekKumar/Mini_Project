PROJ_NAME = AIMatrix
TEST_PROJ_NAME = Test_$(PROJ_NAME)



SRC =	src/list.c \
	src/case_matrixgame.c \
	src/matrix_line_opt.c \
	src/player_mode_opt.c \
	src/diff_lvl_opt.c \
	src/player_mode.c \
	src/key_left_right.c \
	src/key_up_down.c \
	src/list_configs.c \
	src/loop.c \
	src/check_lvl.c \
	src/main.c \
	src/matrixgame.c \
	src/end.c \
	src/print_list.c \
	src/print_mode.c \
	src/print_opti.c \
	src/matrix_struct_opt.c \
	src/matrix_struct_per_line.c \
	src/deloct_malloc.c \
	src/win_display.c

CFLAGS += -I./inc

LDFLAGS = -W -lncurses

RM =	rm -f

CC = gcc

OBJS=	$(SRC:.c=.o)

COV_SRC =unity/unity.c 


TEST_SRC =unity/unity.c 
INC_H = inc
INC_T = unity

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del 
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJS)
	$(CC) -o $(PROJ_NAME) $(OBJS) $(LDFLAGS)
#gcc -I $(INC_H) $(SRC) main.c -o $(call FixPath,$(PROJ_NAME).$(EXEC))

run:
	$(call FixPath,$(PROJ_NAME).$(EXEC))

clean:
	$(RM) $(OBJS)
	$(RM) *.DAT
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov	

test:
	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) $(SRC) $(LDFLAGS) unity/unity.c -o $(call FixPath,$(TEST_PROJ_NAME).$(EXEC))
	./$(call FixPath,$(TEST_PROJ_NAME).$(EXEC))

fclean: clean
	$(RM) $(PROJ_NAME)

re: fclean all

coverage:
	cp test/test_end.c
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H) -I $(INC_T) $(LDFLAGS) unity/unity.c test/test_matrix_line_opt.c  $(SRC) -o $(call FixPath, $(TEST_PROJ_NAME).$(EXEC))
	$(call FixPath, ./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT
	$(RM) test/test_end.c


cppcheck:
	cppcheck --enable=all $(SRC)

debug:
	gcc -I $(INC_H) $(SRC) -g -o $(PROJ_NAME).$(EXEC)
	gdb $(PROJ_NAME).$(EXEC)


valgrind:
	valgrind ./$(TEST_PROJ_NAME).$(EXEC)

.PHONY: all clean fclean re run test doc
