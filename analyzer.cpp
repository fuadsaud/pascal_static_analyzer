#include "analyzer.h"

void variable_declaration(char * variable_name, char * type) {
    printf("%s - %s\n", variable_name, type);
}

void assignment(char * variable_name, int lineno) {
    printf("%s - %d\n", variable_name, lineno);
}
