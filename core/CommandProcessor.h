#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <stdio.h>

#include "InputBuffer.h"

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED,
    META_COMMAND_INVALID_IDENTIFIER,
    META_COMMAND_EXIT
  } MetaCommandType;

MetaCommandType exec_meta_command(InputBuffer* input_buffer);

#endif //COMMANDPROCESSOR_H
