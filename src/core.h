#ifndef CORE_H
#define CORE_H

#include <conio.h>
#include <stdint.h>
#include <stdio.h>

#define MEMORY_SIZE    1024
#define WORD_NUM_BYTES 5

typedef struct
{
    uint8_t bytes[WORD_NUM_BYTES];
} word_t;

#endif
