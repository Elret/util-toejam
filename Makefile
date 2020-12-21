CC = g++
BUILD = .toejam/build/
CFLAG =   
LIBS =  -lboost_filesystem  
DEPS = src/args.h src/create.h src/file_scan.h src/linkedlist.h src/makefile.h src/toejam.h src/usage.h 

toejam: $(BUILD)create.o $(BUILD)args.o $(BUILD)file_scan.o $(BUILD)linkedlist.o $(BUILD)makefile.o $(BUILD)toejam.o $(BUILD)usage.o
	$(CC) $(CFLAG) -o bin/toejam $^ $(LIBS)

$(BUILD)create.o: src/create.cpp $(DEPS)
	$(CC) -c src/create.cpp -o $@

$(BUILD)args.o: src/args.cpp $(DEPS)
	$(CC) -c src/args.cpp -o $@

$(BUILD)file_scan.o: src/file_scan.cpp $(DEPS)
	$(CC) -c src/file_scan.cpp -o $@

$(BUILD)linkedlist.o: src/linkedlist.cpp $(DEPS)
	$(CC) -c src/linkedlist.cpp -o $@

$(BUILD)makefile.o: src/makefile.cpp $(DEPS)
	$(CC) -c src/makefile.cpp -o $@

$(BUILD)toejam.o: src/toejam.cpp $(DEPS)
	$(CC) -c src/toejam.cpp -o $@

$(BUILD)usage.o: src/usage.cpp $(DEPS)
	$(CC) -c src/usage.cpp -o $@

.PHONY: clean

clean:
	rm .toejam/build/*.o
	rm -rf bin
	mkdir bin
