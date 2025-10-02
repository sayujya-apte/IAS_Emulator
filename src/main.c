#include "core.h"
#include "instr.h"
#include "machine.h"
#include "mem.h"

void load_demo()
{
    uint32_t left0  = ((LOAD_MX & OPCODE_MASK) << 12) | 10; // LOAD VALUE AT MEMADDR 10 TO AC
    uint32_t right0 = ((ADD_MX & OPCODE_MASK) << 12) | 11;  // ADD VALUE AT MEMADDR 11 TO AC; STORE RESULT IN AC
    uint64_t word0  = (((uint64_t)left0) << 20) | right0;

    mem_write_word(0, word0);

    uint32_t left1  = ((STOR_MX & OPCODE_MASK) << 12) | 15; // STORE VALUE FROM AC TO MEMADDR 10
    uint32_t right1 = ((HALT & OPCODE_MASK) << 12) | 0;     // HALT
    uint64_t word1  = ((uint64_t)left1 << 20) | right1;

    mem_write_word(1, word1);

    mem_write_word(10, (uint64_t)5 & WORD_40BIT_MASK); // WRITE 5 TO MEMADDR 10
    mem_write_word(11, (uint64_t)7 & WORD_40BIT_MASK); // WRITE 7 TO MEMADDR 11
}

int main(int argc, char* argv[])
{
    IASMachine cpu;
    init_machine(&cpu);

    load_demo();

    printf("INITIALLY:\n");
    printf("MEMORY[10] = %d\n", mem_read_word(10));
    printf("MEMORY[11] = %d\n", mem_read_word(11));
    printf("MEMORY[15] = %d\n", mem_read_word(15));

    while (!cpu.halted)
    {
        run(&cpu);
    }

    printf("\nFINALLY:\n");
    printf("MEMORY[10] = %d\n", mem_read_word(10));
    printf("MEMORY[11] = %d\n", mem_read_word(11));
    printf("MEMORY[15] = %d\n", mem_read_word(15));

    return 0;
}