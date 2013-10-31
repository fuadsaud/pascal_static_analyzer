#include "analyzer.h"

std::map<std::string, std::vector<int> > declarations;
std::map<std::string, std::vector<int> > writes;
std::map<std::string, std::vector<int> > reads;

void variable_declaration(char * variable_name, int lineno) {
    declarations[variable_name].push_back(lineno);
}

void assignment(char * variable_name, int lineno) {
    writes[variable_name].push_back(lineno);
}

void read(char * variable_name, int lineno) {
    reads[variable_name].push_back(lineno);
}

void display_results() {
    std::map<std::string, std::vector<int> >::iterator declaration;

    std::cout << "declarations:" << std::endl;
    for (declaration = declarations.begin(); declaration != declarations.end(); ++declaration) {
        std::cout << "\t" << declaration->first << std::endl;

        for (auto lineno : declaration->second) {
            std::cout << "\t\t" << lineno << std::endl;
        }
    }

    std::map<std::string, std::vector<int> >::iterator write;

    std::cout << "assignments:" << std::endl;
    for (write = writes.begin(); write != writes.end(); ++write) {
        std::cout << "\t" << write->first << std::endl;

        for (auto lineno : write->second) {
            std::cout << "\t\t" << lineno << std::endl;
        }
    }

    std::map<std::string, std::vector<int> >::iterator read;

    std::cout << "reads:" << std::endl;
    for (read = reads.begin(); read != reads.end(); ++read) {
        std::cout << "\t" << read->first << std::endl;

        for (auto lineno : read->second) {
            std::cout << "\t\t" << lineno << std::endl;
        }
    }
}
