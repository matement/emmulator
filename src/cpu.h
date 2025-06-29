#ifndef __CPU_H__
    #define __CPU_H__

#include <stdint.h>

typedef enum{
    //r types
    op_add = 0x0,
    op_sub = 0x1,
    op_and = 0x2,
    op_or = 0x3,
    op_xor = 0x4,
    op_not = 0x5,
    op_shl = 0x6,
    op_shr = 0x7,

    //i types
    op_addi = 0x8,
    op_ldi = 0x9,

    //m type
    op_st = 0xa,
    op_ld = 0xb,

    //b types
    op_beq = 0xc,
    op_bne = 0xd,
    op_jar = 0xe,
    
    //others
    op_halt = 0xf
}OPCODE;



typedef struct{
    uint16_t zero;
    //general purpose registers
    uint16_t saved[8];
    uint16_t temps[8];
    //program counter
    uint16_t pc;
    //stack pointer
    uint16_t sp;
    //memory (16bit memiry adresses)
    uint16_t mem[0x10000];
} CPU;  

CPU init_cpu(CPU cpu);
void emulate(CPU *cpu); 
#endif