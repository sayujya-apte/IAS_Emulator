#ifndef INSTR_H
#define INSTR_H

#include "core.h"
#include "mem.h"

// Split an instruction fetched from a word in memory to an opcode and an operand
void decode_instr(uint32_t instr20, uint8_t* opcode, uint16_t* operand);

// Implementation of the LOAD_MQ instruction
void _LOAD_MQ(IASMachine* machine);

// Implementation of the LOAD_MQ_MX instruction
void _LOAD_MQ_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the STOR_MX instruction
void _STOR_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the LOAD_MX instruction
void _LOAD_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the LOAD_N_MX instruction
void _LOAD_N_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the LOAD_ABS_MX instruction
void _LOAD_ABS_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the ADD_MX instruction
void _ADD_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the ADD_ABS_MX instruction
void _ADD_ABS_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the SUB_MX instruction
void _SUB_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the SUB_ABS_MX instruction
void _SUB_ABS_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the MUL_MX instruction
void _MUL_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the DIV_MX instruction
void _DIV_MX(IASMachine* machine, uint16_t* operand);

// Implementation of the LSH instruction
void _LSH(IASMachine* machine);

// Implementation of the RSH instruction
void _RSH(IASMachine* machine);

#endif