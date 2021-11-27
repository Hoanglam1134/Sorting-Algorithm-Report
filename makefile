CC = g++
TARGET = main
OBJ = DataGenerator.o sort.o sort_with_count.o func.o main.o
CPP = DataGenerator.cpp sort.cpp sort_with_count.cpp func.cpp main.cpp
DEPS = DataGenerator.h sort.h sort_with_count.h func.h

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.cpp (DEPS)
	$(CC)	-c	%.cpp

clean:
	rm -f *.o
	rm $(TARGET)