#include "core.h"
#include "word.h"

int main(int argc, char* argv[])
{
    word_t word;
    word_set(&word, 1000);

    printf("%d\n", word_get(&word));

    return 0;
}