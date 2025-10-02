# IAS Emulator

An emulator for the Institute for Advanced Studies (Von Neumman) machine.
This is a very rudimentary implementation of an emulator for the IAS instruction set. As of right now, it suppports the following instructions:

| OpCode | Instruction | Function                                                |
|--------|-------------|---------------------------------------------------------|
| 0x00   | NOP         | No operation                                            |
| 0x0A   | LOAD_MQ     | Transfer contents of register MQ to the accumulator AC  |
| 0x09   | LOAD_MQ_MX  | Transfer contents of memory location X to MQ            |
| 0x21   | STOR_MX     | Transfer contents of AC to memory location X            |
| 0x01   | LOAD_MX     | Transfer M(X) to the accumulator                        |
| 0x05   | ADD_MX      | Add M(X) to AC; store result in AC                      |
| 0x06   | SUB_MX      | Subtract M(X) from AC; store result in AC               |
| 0x0B   | MUL_MX      | Multiply M(X) by MQ; MS bits → AC, LS bits → MQ         |
| 0x0C   | DIV_MX      | Divide AC by M(X); quotient → MQ, remainder → AC        |
| 0x14   | LSH         | Shift AC left (multiply by 2)                           |
| 0x15   | RSH         | Shift AC right (divide by 2)                            |
| 0xFF   | HALT        | Halts execution                                         |

Currently, you have to write every instruction to memory manually before starting the CPU up. 

### To-do
* Add signed representation
* Implement signed integer instructions like LOAD\_N\_MX, LOAD\_ABS\_MX, ADD\_ABS\_MX, SUB\_ABS\_MX
* Implement branch instructions
* Implement reading and writing to files
* Implement proper instruction cycle