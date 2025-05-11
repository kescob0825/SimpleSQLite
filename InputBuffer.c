#define GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "InputBuffer.h"

// Helper methods below

// This is a helper method to imitate the getline() method part of the
// POSIX standard as the GNU_SOURCE does not import properly through CLion
ssize_t getLine(char **line, size_t *len, FILE *stream)  {

    size_t buffer_size = 128;
    size_t position = 0;
    char *buffer = malloc(buffer_size);
    int c;

    if (!buffer) {
        perror("Error allocating memory for the buffer");
        return -1;
    }

    while ((c = fgetc(stream)) != EOF) {
        if (position >= buffer_size - 1) {
            buffer_size *= 2;
            char *new_buffer = realloc(buffer, buffer_size);
            if (!new_buffer) {
                perror("Error reallocation of memory failed");
                free(buffer);
                return -1;
            }
            buffer = new_buffer;
        }

        buffer[position++] = c;

        if (c == '\n') {
            break;
        }
    }

    if (position == 0 && c == EOF) {
        free(buffer);
        return -1;
    }

    buffer[position] = '\0';

    *line = buffer;
    *len = position;

    return (int)position;
}

// "Class" function below

// Method to initialize the InputBuffer
InputBuffer* new_input_buffer() {

    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    // Set to 0 as get line dynamically changes the buffer size according to the string read
    // This is the actual buffer size
    input_buffer->buffer_length = 0;
    // This is the size of the actual string entered by the user, possibly less than the
    // length of buffer_length
    input_buffer->input_length = 0;

    return input_buffer;
}

// Method that prints out the prompt to the user
void print_prompt() {
    printf("db > ");
}

// Method that reads the input the user entered, utilizing the POSIX standard getline() method
void read_input(InputBuffer* input_buffer) {

    ssize_t bytes_read = getLine(&input_buffer->buffer, &input_buffer->buffer_length, stdin);

    if (bytes_read <= 0) {
        perror("Error reading input from user input failed");
        exit(EXIT_FAILURE);
    }
    // Set end line character
    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = '\0';
}

// Method that frees the buffer from new_input_buffer() and getline() for input_buffer and
// input_buffer->buffer respectively.
void close_input_buffer(InputBuffer* input_buffer) {

    input_buffer->buffer = NULL;

    free(input_buffer->buffer);
    free(input_buffer);
}