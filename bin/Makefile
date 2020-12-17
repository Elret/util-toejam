CC = g++
BUILD = .toejam/build/
LIBS =   
DEPS = src/bob.h src/sam.h src/carl.h src/marie.h src/okay/liz.h src/sarah.h 

bob: $(BUILD)bob.o $(BUILD)sam.o $(BUILD)carl.o $(BUILD)marie.o $(BUILD)liz.o $(BUILD)sarah.o
	$(CC) -o bin/bob $^ $(LIBS)

$(BUILD)bob.o: src/bob.cpp $(DEPS)
	$(CC) -c src/bob.cpp -o $@

$(BUILD)sam.o: src/sam.cpp $(DEPS)
	$(CC) -c src/sam.cpp -o $@

$(BUILD)carl.o: src/carl.cpp $(DEPS)
	$(CC) -c src/carl.cpp -o $@

$(BUILD)marie.o: src/marie.cpp $(DEPS)
	$(CC) -c src/marie.cpp -o $@

$(BUILD)liz.o: src/okay/liz.cpp $(DEPS)
	$(CC) -c src/okay/liz.cpp -o $@

$(BUILD)sarah.o: src/sarah.cpp $(DEPS)
	$(CC) -c src/sarah.cpp -o $@

.PHONY: clean

clean:
	rm .toejam/build/*.o
	rm -rf bin
