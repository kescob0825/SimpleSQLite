#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CommandProcessor.h"

MetaCommandType exec_meta_command(InputBuffer* input_buffer) {
    if (input_buffer->buffer[0] == '.') {
        if (strcmp(input_buffer->buffer, ".exit") == 0) {
            return META_COMMAND_EXIT;
        } else {
            return META_COMMAND_UNRECOGNIZED;
        }
    } else {
        return META_COMMAND_INVALID_IDENTIFIER;
    }
}