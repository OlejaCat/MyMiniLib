#ifndef MY_ASSERTS_H
#define MY_ASSERTS_H

#ifndef NDEBUG
#define assertStrict(expression_string) \
 do \
    {assertStrict_(#expression_string, expression_string, __FILE__, __func__, __LINE__);} \
 while (0)
#else
#   define assertStrict(expesssion_string) ;
#endif

#ifndef NDEBUG
#define assertSoft(expression_string) \
 assertSoft_(#expression_string, expression_string, __FILE__, __func__, __LINE__)
#else
#define assertSoft(expesssion_string) (0)
#endif

#define SIZE_OF_ARRAY(arr) (sizeof(arr) / sizeof(arr[0]))

//----------------------------------------------------------
//! Dublicates an assert functionality
//!
//! @param [in] expression_string  expression that is given
//! @param [in] expression         value of given expression
//! @param [in] file_name          file name where assert is
//! @param [in] line               line where is assert
//-----------------------------------------------------------
void assertStrict_(const char* expression_string,
                   bool        expression,
                   const char* file_name,
                   const char* function_name,
                   int         line);

//---------------------------------------------------------------
//! Dublicates an assert functionality but is just returns State
//!
//! @param [in] expression_string  expression that is given
//! @param [in] expression         value of given expression
//! @param [in] file_name          file name where assert is
//! @param [in] line               line where is assert
//!
//! @return State
//---------------------------------------------------------------
int assertSoft_(const char* expression_string,
                bool        expression,
                const char* file_name,
                const char* function_name,
                int         line);

#endif // MY_ASSERTS_H
