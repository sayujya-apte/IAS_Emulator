#include "instr.h"

void decode_instr(uint32_t instr20, uint8_t* opcode, uint16_t* operand)
{
    uint8_t opc = (instr20 >> 12) & OPCODE_MASK;
    uint8_t opd = (instr20)&OPCODE_MASK;

    *opcode  = opc;
    *operand = opd;
}

void _LOAD_MQ(IASMachine* machine)
{
    machine->AC = machine->MQ;
}

void _LOAD_MQ_MX(IASMachine* machine, uint16_t* operand)
{
    uint64_t memv = mem_read_word(operand);
    machine->MQ   = memv;
}

void _STOR_MX(IASMachine* machine, uint16_t* operand)
{
    mem_write_word(operand, machine->AC);
}

void _LOAD_MX(IASMachine* machine, uint16_t* operand)
{
    uint64_t memv = mem_read_word(operand);
    machine->AC   = memv;
}

void _LOAD_N_MX(IASMachine* machine, uint16_t* operand)
{
    uint64_t memv = ~mem_read_word(operand) + 1;
    machine->AC   = memv;
}

void _LOAD_ABS_MX(IASMachine* machine, uint16_t* operand)
{
    // HOW CAN AN UNSIGNED VALUE HAVE AN ABSOLUTE VALUE
}

void _ADD_MX(IASMachine* machine, uint16_t* operand)
{
    uint64_t memv = mem_read_word(operand);
    machine->AC   = machine->AC + memv;
}

void _ADD_ABS_MX(IASMachine* machine, uint16_t* operand)
{
    // HOW CAN AN UNSIGNED VALUE HAVE AN ABSOLUTE VALUE
}

void _SUB_MX(IASMachine* machine, uint16_t* operand)
{
    uint64_t memv = mem_read_word(operand);
    machine->AC   = machine->AC - memv;
}

void _SUB_ABS_MX(IASMachine* machine, uint16_t* operand)
{
    // HOW CAN AN UNSIGNED VALUE HAVE AN ABSOLUTE VALUE
}

void _MUL_MX(IASMachine* machine, uint16_t* operand)
{
    // -------------------------------------------------
    // -------- WARNING : AI GENERATED FUNCTION --------
    // BECAUSE I COULDN'T FIGURE OUT HOW TO DO IT MYSELF
    // -------------------------------------------------

    uint64_t a = machine->MQ;
    uint64_t b = mem_read_word(operand);

    uint64_t a_low  = (uint32_t)(a & 0xFFFFFFFF);
    uint64_t a_high = (uint32_t)(a >> 32);
    uint64_t b_low  = (uint32_t)(b & 0xFFFFFFFF);
    uint64_t b_high = (uint32_t)(b >> 32);

    uint64_t low_low   = a_low * b_low;
    uint64_t low_high  = a_low * b_high;
    uint64_t high_low  = a_high * b_low;
    uint64_t high_high = a_high * b_high;

    uint64_t mid1 = low_high + (low_low >> 12);
    uint64_t mid2 = high_low;

    uint64_t mid_sum = mid1 + mid2;

    uint64_t lower = (low_low & 0xFFFFFFFF) | (mid_sum << 32);
    uint64_t upper = high_high + (mid_sum >> 32);

    machine->AC = upper;
    machine->MQ = lower;
}

void _DIV_MX(IASMachine* machine, uint16_t* operand)
{
    uint64_t divisor = mem_read_word(operand);
    if (divisor == 0)
        return;

    machine->MQ = machine->AC / divisor;
    machine->AC = machine->AC % divisor;
}

void _LSH(IASMachine* machine)
{
    machine->AC = machine->AC << 1;
}

void _RSH(IASMachine* machine)
{
    machine->AC = machine->AC >> 1;
}
