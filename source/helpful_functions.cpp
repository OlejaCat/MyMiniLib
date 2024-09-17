#include "../include/helpful_functions.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/string_color.h"


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


void assertStrict_(const char* expression_string,
                   const bool  expression,
                   const char* file_name,
                   const char* function_name,
                   const int   line)
{
    if (expression) { return ; }

    fprintf(stderr,
            BOLD_RED "Assert failed:\t%s\nSource:\t\t%s:%d\nIn function:\t%s\n" RESET,
            expression_string,
            file_name,
            line,
            function_name);
    abort();
}


int assertSoft_(const char* expression_string,
                  const bool  expression,
                  const char* file_name,
                  const char* function_name,
                  const int   line)
{
    if (expression) { return 0; }

    fprintf(stderr,
            BOLD_RED "Assert failed:\t%s\nSource:\t\t%s:%d\nIn function:\t%s\n" RESET,
            expression_string,
            file_name,
            line,
            function_name);
    return 1;
}


void clearScreen(void)
{
    system("clear");
}


bool equatTwoDoubles(const double a, const double b)
{
    return (fabs(a - b) < EPS);
}


bool compareGreaterTwoDoubles(const double a, const double b)
{
    return (a - b > EPS);
}


bool compareLessTwoDoubles(const double a, const double b)
{
    return (b - a > EPS);
}


void swap(void* data_a, void* data_b, size_t size)
{
    assertStrict(data_a != NULL);
    assertStrict(data_b != NULL);

    size_t counter_64 = size / sizeof(uint64_t);

    uint64_t  temp_64 = 0;
    uint64_t* casted_64_a = (uint64_t*)data_a;
    uint64_t* casted_64_b = (uint64_t*)data_b;

    for (size_t i = 0; i < size / sizeof(uint64_t); i++)
    {
        temp_64 = casted_64_a[i];
                  casted_64_a[i] = casted_64_b[i];
                                   casted_64_b[i] = temp_64;
    }

    uint8_t temp_8 = 0;
    uint8_t* casted_8_a = (uint8_t*)data_a;
    uint8_t* casted_8_b = (uint8_t*)data_b;

    for (size_t i = counter_64 * sizeof(uint64_t); i < size; i++)
    {
        temp_8 = casted_8_a[i];
                 casted_8_a[i] = casted_8_b[i];
                                 casted_8_b[i] = temp_8;
    }
}


bool isInf(const double n)
{
    return isNan(n * 0.0);
}


bool isNan(const double n)
{
    return n != n;
}


bool isFinite(const double n)
{
    return !isInf(n) && !isNan(n);
}
