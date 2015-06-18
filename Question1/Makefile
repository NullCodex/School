# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
VERSION = -std=c++0x

# the build target executable:
TARGET = Straights
SOURCES = *.cpp

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(VERSION) $(SOURCES) -o $(TARGET)

clean:
	$(RM) $(TARGET)