#ifndef INPUTBUFFER_H
#define INPUTBUFFER_H

#include <stdio.h>
// This is a small wrapper class to store some state of the
// InputBuffer in order to interact with a "getline()" function.
typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();

void print_prompt();

void read_input(InputBuffer* input_buffer);

#endif //INPUTBUFFER_H
