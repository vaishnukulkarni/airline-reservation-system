PROJECT_NAME=AIRLINE_RESERVATION_SYSTEM
#ifdef OS
RM=del/q
Fixpath=$(subst /,\,$1)
EXEC=exe
else
ifeq($(shell uname),Linux)
RM=rm -rf
Fixpath=$1
EXEC=out
end if
end if
#output directore
BUILD=build
#All source code files
SRC=airline.c\
src\reserve.c

#All test sources
TEST_SRC=airline.c\
src\reserve.c\
test/test_airline.c\
unity/unity.c
TEST_OUTPUT=$(BUILD)/TEST_$(PROJECT_NAME).$(EXEC)
INC =-Iinc\
-Iunity
all:$(SRC)$(INC) -o$(call Fixpath,$(PROJ_NAME).$(EXEC)) -lm
run :all
./$(call Fixpath,$(PROJ_NAME).$(EXEC))
build_test:
gcc $(TEST_SRC) $(INC) $(INCLUDE_LIBS) -o $(call Fixpath,$(PROJ_NAME).$(EXEC)) -lm
run_test:build test
./$(call FixPth,$(PROJ_NAME).(EXEC))
analyze:test mmecheck staticcheck coverage sanitize_check
staticcheck:
cppcheck --enable=all -iunity .
memcheck:
valgrind ./$(TEST_OUTPUT)
sanitize_check:
gcc -fsanitize=address -fno-omit-frame-pointer$(TEST_SRC) $(INC) -o $(TEST_OUTPUT)
./$(TEST_OUTPUT)
clean:
$(RM)$(call FixPath,$(PROJ_NAME).$(EXEC))

