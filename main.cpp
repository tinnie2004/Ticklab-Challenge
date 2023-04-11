#include "lexer.h"

int main(int argc, char ** argv) {
    string file_input(argv[1]);
    getFile* head = NULL;
    Label* lable_test = NULL;
    LabelList* labellist = NULL;
    checkSyntax(file_input, head, lable_test, labellist);
    return 0;
}