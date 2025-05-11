#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/InputBuffer.h"
#include "core/CommandProcessor.h"

void main(int argc, char* argv[]) {

    InputBuffer* input_buffer = new_input_buffer();
    while (true) {
        print_prompt();
        read_input(input_buffer);

        switch (exec_meta_command(input_buffer)) {
                case META_COMMAND_SUCCESS:
                    continue;
                case (META_COMMAND_UNRECOGNIZED):
                    printf("Unrecognized command '%s'\n", input_buffer->buffer);
                    continue;
                case (META_COMMAND_INVALID_IDENTIFIER):
                    printf("Invalid identifier, a command must contain a '.' as the leading character\n", input_buffer->buffer);
                continue;
        }
    }
}
