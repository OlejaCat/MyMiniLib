#ifndef HELPFUL_FUNCTIONS_H
#define HELPFUL_FUNCTIONS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>


#define FREE_NULL(point_) free(point_); \
                          point_ = NULL

#define FCLOSE_NULL(file_) fclose(file_); \
                           file_ = NULL

typedef enum ClearBufferMessage
{
    ClearBufferMessage_NOT_ONLY_SPACES = 0,
    ClearBufferMessage_ONLY_SPACES     = 1,
} ClearBufferMessage;

//-----------------------------
//! Gets file and returns its size
//!
//! @param [in] file point to file
//!
//! @return Size of file
size_t getFileSize(FILE* file);

//----------------------------------------------
//! Swaps two numbers in double format
//!
//! @param [out] a     First variable
//! @param [out] b     Second variable
//! @param [in]  size  Size of type of variable
//!
//! @note Variables need to be in one type
//----------------------------------------------
void swap(void* a, void* b, size_t size);

//----------------
//! Cleans screen
//----------------
void clearScreen(void);

//----------------------------------------------------------------------------
//! Clears input buffer
//!
//! @return  if buffer wa only spaces returns ClearBufferMessage_ONLY_SPACES
//!          and ClearBufferMessage_NOT_ONLY_SPACES if not
//----------------------------------------------------------------------------
ClearBufferMessage clearBuffer(void);

#endif // HELPFUL_FUNCTIONS_H
