CC = g++
CFLAGS = -Wall
LIBS = -lboost_filesystem

SRC := src
BUILD := .toejam/build
HEADERS := $(wildcard $(SRC)/*.h)

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(BUILD)/%.o, $(SOURCES))

toejam: $(OBJECTS)
	$(CC) $(CFLAGS) -g -o $@ $^ $(LIBS)

$(BUILD)/%.o: $(SRC)/%.cpp $(HEADERS)
	$(CC) -I $(CFLAGS) $(SRC) -c $< -o $@ $(LIBS)
	
.PHONY: clean

clean:
	rm -f .toejam/build/*.o 
	rm -f bin/toejam-dev

.PHONY: clean_bin

clean_bin:
	rm -rf bin/.toejam
	rm bin/Makefile
	rm -rf bin/src
	
install:
	mkdir -p $(DESTDIR)/usr/bin
	install -m 0755 toejam $(DESTDIR)/usr/bin/toejam
