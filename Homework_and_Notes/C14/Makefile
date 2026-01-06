CC=g++
STD=c++11

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

build/test_exercises: build/test_exercises.o
	$(CC) -o $@ $^ -std=$(STD)

-include build/*.d

.PHONY: test all clean

test_all: build/test_exercises
	./build/test_exercises

test: test_all

clean:
	rm -rf build

