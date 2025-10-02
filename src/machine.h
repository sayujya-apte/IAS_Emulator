#ifndef MACHINE_H
#define MACHINE_H

#include "core.h"
#include "instr.h"
#include "mem.h"

// Initialize the cpu and the memory
void init_machine(IASMachine* machine);

// Execute the given instruction
void exec(IASMachine* machine, uint8_t operator, uint16_t operand);

// Step through one instruction at a time
void run(IASMachine* machine);

#endif
