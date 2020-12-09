NAME = special_stack
TEST = $(NAME)_test

C_FILES:= $(shell find ./src -name *.c)
INCLUDES:= -I ./include 
DEPS = ./include/*.h
LIB_PATH = /home/liorcoeh/git/lior-cohen/DifferentQuestions/SpecialStack/lib

CC = g++
CFLAGS = -std=c++11 -pedantic-errors -Wall -Wextra -g 				# For Debbuging
LDFLAGS = -std=c++11 -pedantic-errors -Wall -Wextra -DNDEBUG -O3 	# Not Debbug

# Link the test binary to shared objects
test:  libsstack.so ./test/$(TEST).c $(DEPS)
	@$(CC) -L./lib -Wl,-rpath=$(LIB_PATH) $(INCLUDES) $(LDFLAGS) -o $(TEST) ./$@/$(TEST).c -lsstack
	@mv $(TEST) ./$@/bin
	@./$@/bin/$(TEST) 

debug:	./test/$(TEST).c libsstack.so $(DEPS)
		@$(CC) -L./lib -Wl,-rpath=$(LIB_PATH) $(INCLUDES) $(CFLAGS) ./test/$(TEST).c -o main -lsstack
		@mv main ./test/debbuging 

libsstack.so: $(C_FILES) $(DEPS) 
	@$(CC) $(INCLUDES) $(CFLAGS) $(C_FILES) -fPIC -shared -o $@
	@mv $@ ./lib
		
gt: ./test/bin/main
	clear
	@gdbtui ./test/bin/main
	
vlg: ./test/bin/$(NAME)_test
	@valgrind --leak-check=full --leak-check=full --show-leak-kinds=all --track-origins=yes ./test/bin/$(NAME)_test

.PHONY: clean

clean:
	 @rm -f -R *.o *.so *_test
