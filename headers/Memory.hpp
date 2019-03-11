#ifndef MEMORY_H
#define MEMORY_H

class Memory {

private:
  int *mem;
  bool *locked;
  int size;

public:
  Memory(int size, int valueToInitialise = 0);
  ~Memory();
  int read(int address);
  bool write(int address, int value);
  bool lockMem(int address);
  bool unlockMem(int address);
  void logAll();
};

#endif