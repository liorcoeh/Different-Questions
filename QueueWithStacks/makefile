NAME = queue_with_stacks
TEST = $(NAME)_test

C_FILES:= $(shell find ./src -name *.c)
INCLUDES:= -I ./include 
DEPS = ./include/*.h
LIB_PATH = /home/liorcoeh/git/lior-cohen/DifferentQuestions/QueueWithStacks/lib

CC = g++
CFLAGS = -std=c++11 -pedantic-errors -Wall -Wextra -g 				# For Debbuging
LDFLAGS = -std=c++11 -pedantic-errors -Wall -Wextra -DNDEBUG -O3 	# Not Debbug

# Link the test binary to shared objects
test:  libqws.so ./test/$(TEST).c $(DEPS)
	@$(CC) -L./lib -Wl,-rpath=$(LIB_PATH) $(INCLUDES) $(LDFLAGS) -o $(TEST) ./$@/$(TEST).c -lqws
	@mv $(TEST) ./$@/bin
	@./$@/bin/$(TEST) 

debug:	./test/$(TEST).c libqws.so $(DEPS)
		@$(CC) -L./lib -Wl,-rpath=$(LIB_PATH) $(INCLUDES) $(CFLAGS) ./test/$(TEST).c -o main -lqws
		@mv main ./test/debbuging 

libqws.so: $(C_FILES) $(DEPS) 
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
