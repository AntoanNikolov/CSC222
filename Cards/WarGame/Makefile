CC=g++
STD=c++11

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

build/test_cards: build/test_cards.o build/random.o build/Cards.o
	$(CC) -o $@ $^ -std=$(STD)

build/test_decks: build/test_decks.o build/random.o build/Cards.o 
	$(CC) -o $@ $^ -std=$(STD) 

-include build/*.d

.PHONY: test all clean

test_cards: build/test_cards
	./build/test_cards

test_decks: build/test_decks
	./build/test_decks

test: test_cards test_decks

clean:
	rm -rf build

