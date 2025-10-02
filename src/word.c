#include "word.h"

void word_set(word_t* w, uint64_t val)
{
    for (int i = 0; i < WORD_NUM_BYTES; i++)
    {
        w->bytes[i] = (val >> (8 * i)) & 0xFF;
    }
}

uint64_t word_get(const word_t* w)
{
    uint64_t value = 0;

    for (int i = 0; i < WORD_NUM_BYTES; i++)
    {
        value |= ((uint64_t)w->bytes[i]) << (8 * i);
    }

    return value;
}

void word_clear(word_t* w)
{
    for (int i = 0; i < WORD_NUM_BYTES; i++)
    {
        w->bytes[i] = 0;
    }
}

void word_copy(word_t* src, word_t* dest)
{
    for (int i = 0; i < WORD_NUM_BYTES; i++)
    {
        dest->bytes[i] = src->bytes[i];
    }
}
