CC = g++
BUILD = .toejam/build/
CFLAG =   
LIBS =   
DEPS = src/bob.h src/test/sally.h src/test/smith.h 

bob: $(BUILD)bob.o $(BUILD)sally.o $(BUILD)smith.o
	$(CC) $(CFLAG) -o bin/bob $^ $(LIBS)

$(BUILD)bob.o: src/bob.cpp $(DEPS)
	$(CC) -c src/bob.cpp -o $@

$(BUILD)sally.o: src/test/sally.cpp $(DEPS)
	$(CC) -c src/test/sally.cpp -o $@

$(BUILD)smith.o: src/test/smith.cpp $(DEPS)
	$(CC) -c src/test/smith.cpp -o $@

.PHONY: clean

clean:
	rm .toejam/build/*.o
	rm -rf bin
	mkdir bin
