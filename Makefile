CC = g++
CFLAGS = 
LIBS = -lboost_filesystem

SRC := src
BUILD := .toejam/build
HEADERS := $(wildcard $(SRC)/*.h)

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(BUILD)/%.o, $(SOURCES))

toejam-dev: $(OBJECTS)
	$(CC) $^ -o bin/$@ $(LIBS)

$(BUILD)/%.o: $(SRC)/%.cpp $(HEADERS)
	$(CC) -I $(SRC) -c $< -o $@ $(LIBS)
	
.PHONY: clean

clean:
	rm -f .toejam/build/*.o 
	rm -f bin/toejam-dev

.PHONY: clean_bin

clean_bin:
	rm -rf bin/.toejam
	rm bin/Makefile
	rm -rf bin/src
