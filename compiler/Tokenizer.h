#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "../core/InputBuffer.h"

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT
} PreparationType;

typedef enum {
  STATEMENT_INSERT,
  STATEMENT_SELECT
} StatementType;

typedef struct {
  StatementType statement_type;
} Statement;

PreparationType prepare_statement(InputBuffer* input_buffer, Statement* statement);

#endif //TOKENIZER_H
