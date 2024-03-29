#include "../headers/Memory.hpp"

#include <iostream>

Memory::Memory(std::string name, int size, int valueToInitialise/* = 0 */) {
  
  this->name = name;
  
  mem = new int[size];
  locked = new bool[size];
  this->size = size;

  for(int i = 0; i < size; i++) {
    mem[i] = valueToInitialise;
    locked[i] = false;
  }
}

Memory::~Memory() {

  delete [] mem;
}

int Memory::read(int address) {

  if (address >= size) {
    std::cout<<"Index error: address out of bounds";
    return -1;
  }

  return mem[address];
}

bool Memory::write(int address, int value) {

  if (address >= size) {
    std::cout<<"Index error: address out of bounds";
    return false;
  }

  if (locked[address]) {
    std::cout<<"Error: memory address is locked";
    return false;
  }

  mem[address] = value;

  return true;
}

bool Memory::lockMem(int address) {
  
  if (!locked[address]) {
    locked[address] = true;
    return true;
  }
  return false;
}

bool Memory::unlockMem(int address) {

  if (locked[address]) {

    locked[address] = false;
    return true;
  }
  return false;
}

void Memory::logAll() {

  std::cout<<"Logging all words from "<<this->name<<".\n";
  for(int i = 0; i < size; i++) {
    std::cout<<i<<": "<<mem[i]<<'\n';
  }
}
