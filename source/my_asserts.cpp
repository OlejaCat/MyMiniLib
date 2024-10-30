#include "my_asserts.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/string_color.h"


void abortWithMessage_(const char* message,
                       const char* file_name,
                       const char* function_name,
                       const int   line)
{
    fprintf(stderr,
            BOLD_RED "Abort:\t%s\nSource:\t\t%s:%d\nIn function:\t%s\n" RESET,
            message,
            file_name,
            line,
            function_name);
    abort();
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
