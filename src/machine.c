#include "machine.h"

void init_machine(IASMachine* machine)
{
    machine->PC        = 0;
    machine->AC        = 0;
    machine->MQ        = 0;
    machine->IBR_valid = false;
    machine->halted    = false;
}

void exec(IASMachine* machine, uint8_t opcode, uint16_t operand)
{
    int64_t ac_s, mem_s;

    switch (opcode)
    {
    case NOP:
        break;
    case LOAD_MQ:
        _LOAD_MQ(machine);
        break;
    case LOAD_MQ_MX:
        _LOAD_MQ_MX(machine, operand);
        break;
    case STOR_MX:
        _STOR_MX(machine, operand);
        break;
    case LOAD_MX:
        _LOAD_MX(machine, operand);
        break;
    case LOAD_N_MX:
        _LOAD_N_MX(machine, operand);
        break;
    case LOAD_ABS_MX:
        _LOAD_ABS_MX(machine, operand);
        break;
    case ADD_MX:
        _ADD_MX(machine, operand);
        break;
    case ADD_ABS_MX:
        _ADD_ABS_MX(machine, operand);
        break;
    case SUB_MX:
        _SUB_MX(machine, operand);
        break;
    case SUB_ABS_MX:
        _SUB_ABS_MX(machine, operand);
        break;
    case MUL_MX:
        _MUL_MX(machine, operand);
        break;
    case DIV_MX:
        _DIV_MX(machine, operand);
        break;
    case LSH:
        _LSH(machine);
        break;
    case RSH:
        _RSH(machine);
        break;
    case HALT:
        machine->halted = true;
        break;
    default:
        fprintf(stderr, "Unknown opcode 0x%02X at PC=%u\n", opcode, machine->PC);
        machine->halted = true;
        break;
    }
}

void run(IASMachine* machine)
{
    if (machine->halted)
    {
        return;
    }

    if (machine->IBR_valid)
    {
        uint32_t instr20 = machine->IBR & INSTR_20BIT_MASK;
        uint8_t  op;
        uint16_t addr;
        decode_instr(machine->IBR, &op, &addr);
        machine->IBR_valid = false;

        exec(machine, op, addr);

        return;
    }

    uint64_t word = mem_read_word(machine->PC);

    uint32_t left  = (uint32_t)((word >> 20) & INSTR_20BIT_MASK);
    uint32_t right = (uint32_t)(word & INSTR_20BIT_MASK);

    machine->IBR       = left;
    machine->IBR_valid = true;

    if (left != 0)
    {
        uint8_t  op;
        uint16_t addr;
        decode_instr(left, &op, &addr);

        if (right != 0)
        {
            machine->IBR       = right;
            machine->IBR_valid = true;
        }

        machine->PC++;

        exec(machine, op, addr);
    }
    else
    {
        if (right != 0)
        {
            uint8_t  op;
            uint16_t addr;
            decode_instr(right, &op, &addr);

            machine->PC++;
            exec(machine, op, addr);
        }
        else
        {
            machine->PC++;
        }
    }
}
