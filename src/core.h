#ifndef CORE_H
#define CORE_H

#include <conio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define MEMORY_SIZE 1024 // Maximum words in memory

#define WORD_40BIT_MASK  0xFFFFFFFFFFULL   // 40 bit mask
#define INSTR_20BIT_MASK ((1U << 20) - 1U) // 20 bit mask
#define OPCODE_MASK      0xFF              // 8-bit opcode mask
#define OPERAND_MASK     0xFFF             // 12-bit operand mask

typedef struct
{
    uint64_t AC;        // Accumulator
    uint64_t MQ;        // Index Register
    uint64_t PC;        // Program Counter
    uint32_t IBR;       // Instruction Buffer Register
    bool     IBR_valid; // Whether IBR has an instruction pending
    bool     halted;    // Whether machine is halted or not
} IASMachine;

uint64_t MEMORY[MEMORY_SIZE];

typedef enum
{
    NOP         = 0x00, // No operation
    LOAD_MQ     = 0x0A, // Transfer contents of register MQ to the accumulator AC
    LOAD_MQ_MX  = 0x09, // Transfer contents of memory location X to MQ
    STOR_MX     = 0x21, // Transfer contents of AC to memory location X
    LOAD_MX     = 0x01, // Transfer M(X) to the accumulator
    LOAD_N_MX   = 0x02, // Transfer -M(X) to the accumulator
    LOAD_ABS_MX = 0x03, // Transfer absolute value of M(X) to the accumulator
    ADD_MX      = 0x05, // Add M(X) to AC; store result in AC
    ADD_ABS_MX  = 0x07, // Add absolute value of M(X) to AC
    SUB_MX      = 0x06, // Subtract M(X) from AC; store result in AC
    SUB_ABS_MX  = 0x08, // Subtract absolute value of M(X) from AC
    MUL_MX      = 0x0B, // Multiply M(X) by MQ; most significant bits → AC, least significant bits → MQ
    DIV_MX      = 0x0C, // Divide AC by M(X); quotient → MQ, remainder → AC
    LSH         = 0x14, // Shift AC left (multiply by 2)
    RSH         = 0x15, // Shift AC right (divide by 2)
    HALT        = 0xFF  // Halts execution
} opcode_t;

static inline uint64_t mask40(uint64_t val)
{
    return val & WORD_40BIT_MASK;
}

#endif
