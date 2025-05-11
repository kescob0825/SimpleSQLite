#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compiler/Tokenizer.h"
#include "core/InputBuffer.h"
#include "core/CommandProcessor.h"
#include "core/VirtualMachine.h"

int main(int argc, char* argv[]) {

    InputBuffer* input_buffer = new_input_buffer();
    while (true) {
      print_prompt();
      read_input(input_buffer);

      if (input_buffer->buffer[0] == '.') {
        switch (exec_meta_command(input_buffer)) {
          case META_COMMAND_SUCCESS:
            break;
          case (META_COMMAND_EXIT):
            close_input_buffer(input_buffer);
            printf("Exiting...\n");
            exit(EXIT_SUCCESS);
          case (META_COMMAND_UNRECOGNIZED):
            printf("Unrecognized command '%s'\n", input_buffer->buffer);
            continue;
        }
      }

      Statement statement;
      switch (prepare_statement(input_buffer, &statement)) {
        case (PREPARE_SUCCESS):
          execute_statement(&statement);
          break;
        case (PREPARE_UNRECOGNIZED_STATEMENT):
          printf("Unrecognized keyword at start of '%s'\n", input_buffer->buffer);
          continue;
      }
    }
    close_input_buffer(input_buffer);
    return EXIT_SUCCESS;
}
