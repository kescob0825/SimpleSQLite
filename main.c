#include <stdbool.h>
#include "InputBuffer.h"

int main(int argc, char* argv[]) {

    InputBuffer* input_buffer = new_input_buffer();
    while (true) {
        print_prompt();
        read_input(input_buffer);
        break;
    }
    return 0;
}
