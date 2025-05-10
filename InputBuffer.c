#define GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "InputBuffer.h"

// Helper methods below
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
InputBuffer* new_input_buffer() {

    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

void print_prompt() {
    printf("db > ");
}

void read_input(InputBuffer* input_buffer) {

    ssize_t bytes_read = getLine(&input_buffer->buffer, &input_buffer->buffer_length, stdin);

    if (bytes_read <= 0) {
        perror("Error reading input from stdin failed");
        exit(EXIT_FAILURE);
    }

    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = '\0';
}