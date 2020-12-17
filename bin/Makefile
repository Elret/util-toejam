CC = g++
BUILD = .toejam/build/
CFLAG =  -Wall  
LIBS =  -lboost_filesystem  
DEPS = src/bob.h 

bob: $(BUILD)bob.o
	$(CC) $(CFLAG) -o bin/bob $^ $(LIBS)

$(BUILD)bob.o: src/bob.cpp $(DEPS)
	$(CC) -c src/bob.cpp -o $@

.PHONY: clean

clean:
	rm .toejam/build/*.o
	rm -rf bin
	mkdir bin
