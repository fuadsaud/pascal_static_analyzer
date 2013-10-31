#include "analyzer.h"

std::map<std::string, std::vector<int> > declarations;
std::map<std::string, std::vector<int> > reads;
std::map<std::string, std::vector<int> > writes;

void variable_declaration(char * variable_name, int lineno) {
    declarations[variable_name].push_back(lineno);
    std::cout << declarations[variable_name].back() << std::endl;
}

void assignment(char * variable_name, int lineno) {
    writes[variable_name].push_back(lineno);
    std::cout << writes[variable_name].back() << std::endl;
}

void read(char * variable_name, int lineno) {
    reads[variable_name].push_back(lineno);
    std::cout << "read" << std::endl;
    std::cout << reads[variable_name].back() << std::endl;
}
