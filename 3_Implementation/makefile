# Output directory
BUILD = build

# All source code files
SRC = airline.c\
src/reserve.c\
test/test_airline.c\
unity/unity.c
-I ../src\
#src/reserve.c\


# All test source files
TEST_SRC = _I ../src\
#src/reserve.c\

test/test_airline.c\
unity/unity.c\

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).exe

# All include folders with header files
INC	= inc/airline.h\
reserve.h\
-I ../unity\

#Library Inlcudes
#INCLUDE_LIBS = 
INCLUDE_LIBS = -lcunit



# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(SRC) $(BUILD)
	    gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).exe



# Document the code using Doxygen
doc:
	    make -C ./documentation

# Build and run the unit tests
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
		.\$(TEST_OUTPUT)

    

analyze: test memcheck staticcheck coverage sanitize_check

staticcheck:
	    cppcheck --enable=all -iunity .

memcheck:
	    valgrind ./$(TEST_OUTPUT)

sanitize_check:
	gcc -fsanitize=address -fno-omit-frame-pointer $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
	./$(TEST_OUTPUT)

coverage:$(TEST_SRC)
	gcc -fprofile-arcs -ftest-coverage $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
	.\$(TEST_OUTPUT)
	gcov -a reserve.c	

# Remove all the built files, invoke by `make clean`
clean:
#	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT) *.gcda *.gcno *.gcov
	rm -rf $(BUILD) *.gcda *.gcno *.gcov

# Create new build folder if not present
$(BUILD):
	    mkdir build
