#ifndef MEM_H
#define MEM_H

#include "core.h"

// Read a word at a given memory address
uint64_t mem_read_word(uint16_t addr);

// Write a given value to a word at a given memory address
void mem_write_word(uint16_t addr, uint64_t val);

#endif
