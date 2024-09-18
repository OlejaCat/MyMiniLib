#include "../include/helpful_functions.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/my_asserts.h"


void clearScreen(void)
{
    system("clear");
}


size_t getFileSize(FILE* file) {
    assertStrict(file != NULL);

    fseek(file, 0, SEEK_END);
    long int size_of_file = ftell(file);
    rewind(file);

    return (size_t)size_of_file;
}


ClearBufferMessage clearBuffer(void)
{
    int current_char = 0;
    bool only_spaces = true;

    while ((current_char = getchar()) != (int)'\n' && current_char != EOF)
    {
        if (!isspace((char)current_char))
        {
            only_spaces = false;
        }
    }

    return (only_spaces)
                ? ClearBufferMessage_ONLY_SPACES
                : ClearBufferMessage_NOT_ONLY_SPACES;
}


void swap(void* data_a, void* data_b, size_t size)
{
    assertStrict(data_a != NULL);
    assertStrict(data_b != NULL);

    size_t counter_64 = size / sizeof(uint64_t);

    uint64_t* casted_64_a = (uint64_t*)data_a;
    uint64_t* casted_64_b = (uint64_t*)data_b;

    for (size_t i = 0; i < counter_64; i++)
    {
        uint64_t  temp_64 = 0;

        memcpy(&temp_64, casted_64_a + i, sizeof(uint64_t));
                  memcpy(casted_64_a + i, casted_64_b + i, sizeof(uint64_t));
                                   memcpy(casted_64_b + i, &temp_64, sizeof(uint64_t));
    }

    uint8_t* casted_8_a = (uint8_t*)data_a;
    uint8_t* casted_8_b = (uint8_t*)data_b;

    for (size_t i = counter_64 * sizeof(uint64_t); i < size; i++)
    {
        uint8_t temp_8 = 0;

        temp_8 = casted_8_a[i];
                 casted_8_a[i] = casted_8_b[i];
                                 casted_8_b[i] = temp_8;
    }
}
