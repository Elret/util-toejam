CC = g++
CLAGS = 
DEPS = $(wildcard src/*.h)
OBJ = $(wildcard src/*.cpp)


LIBS= -lboost_filesystem


%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

toejam: $(OBJ)
	$(CC) -o bin/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean: 
	rm -f src/*.o
	rm -f toejam