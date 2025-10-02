#ifndef WORD_H
#define WORD_H

#include "core.h"

void word_set(word_t* w, uint64_t val);

uint64_t word_get(const word_t* w);

void word_clear(word_t* w);

void word_copy(word_t* src, word_t* dest);

#endif
