#include <string.h>

#include "Tokenizer.h"

PreparationType prepare_statement(InputBuffer* input_buffer, Statement* statement) {

  if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
    statement->statement_type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  } else if (strncmp(input_buffer->buffer, "select", 6) == 0) {
    statement->statement_type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  } else {
    return PREPARE_UNRECOGNIZED_STATEMENT;
  }
}