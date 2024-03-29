CC = g++
CFLAGS = -g -Wall -I .
TARGET = cpu

MODULES = sources/CPU.cpp sources/InstructionRegister.cpp \
				sources/Memory.cpp sources/ALU.cpp

TEST_FILES = tests/$(TARGET).cpp tests/ALU.cpp \
				tests/Memory.cpp tests/InstructionRegister.cpp

all: $(TARGET)

$(TARGET): 	main.cpp $(MODULES)
	$(CC) $(CFLAGS) main.cpp $(MODULES) -o $(TARGET)

test: $(MODULES) $(TEST_FILES)
	$(CC) $(CFLAGS) $(MODULES) $(TEST_FILES) -o test-suite

clean:
	$(RM) $(TARGET)
	$(RM) test-suite
