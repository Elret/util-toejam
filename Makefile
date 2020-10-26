CC = g++
CFLAGS = -Wall
LIBS = -lboost_filesystem

SRC := src
BUILD := .toejam/build
HEADERS := $(wildcard $(SRC)/*.h)

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(BUILD)/%.o, $(SOURCES))

toejam: $(OBJECTS)
	$(CC) $(CFLAGS) -g -o bin/$@ $^ $(LIBS)

$(BUILD)/%.o: $(SRC)/%.cpp $(HEADERS)
	$(CC) -I $(CFLAGS) $(SRC) -c $< -o $@ $(LIBS)
	
.PHONY: clean

clean:
	rm -f .toejam/build/*.o 
	rm -f bin/toejam

.PHONY: bin

bin:
	rm -rf bin
	mkdir bin
	
install:
	mkdir -p $(DESTDIR)/usr/bin
	install -m 0755 toejam $(DESTDIR)/usr/bin/toejam
