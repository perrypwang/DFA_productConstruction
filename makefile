#the compiler: g++ for c++ programs
CC = g++

#compiler flags:
CFLAGS = -std=c++11

#the build target executable
TARGET = product

all: $(TARGET)

$(TARGET) : $(TARGET).cc
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cc

clean:
	$(RM) $(TARGET)
