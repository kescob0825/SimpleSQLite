#include <stdio.h>

#include "VirtualMachine.h"

void execute_statement(Statement* statement) {

  switch (statement->statement_type) {
    case STATEMENT_INSERT:
      printf("INSERT\n");
      break;
    case STATEMENT_SELECT:
      printf("SELECT\n");
      break;
  }
}