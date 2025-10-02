#include "mem.h"

uint64_t mem_read_word(uint16_t addr)
{
    if (addr >= MEMORY_SIZE)
    {
        fprintf(stderr, "mem read oob %u\n", addr);
        exit(1);
    }

    return MEMORY[addr] & WORD_40BIT_MASK;
}

void mem_write_word(uint16_t addr, uint64_t val)
{
    if (addr >= MEMORY_SIZE)
    {
        fprintf(stderr, "mem read oob %u\n", addr);
        exit(1);
    }

    MEMORY[addr] = val & WORD_40BIT_MASK;
}
