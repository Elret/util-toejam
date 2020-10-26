CC = g++
SRC = src/
BUILD = .toejam/build/
LIBS =  -lboost_filesystem  
DEPS = $(SRC)main.h $(SRC)file_scan.h $(SRC)linkedlist.h 

main: $(BUILD)main.o $(BUILD)file_scan.o $(BUILD)linkedlist.o
	$(CC) -o main $^ $(LIBS)

$(BUILD)main.o: $(SRC)main.cpp $(DEPS)
	$(CC) -c $(SRC)main.cpp -o $@

$(BUILD)file_scan.o: $(SRC)file_scan.cpp $(DEPS)
	$(CC) -c $(SRC)file_scan.cpp -o $@

$(BUILD)linkedlist.o: $(SRC)linkedlist.cpp $(DEPS)
	$(CC) -c $(SRC)linkedlist.cpp -o $@

