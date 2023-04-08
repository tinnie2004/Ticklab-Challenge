#include "lexer.h"

int main(int argc, char ** argv) {
    string file_input(argv[1]);
    getFile* head = NULL;
    checkSyntax(file_input, head);
    return 0;
}