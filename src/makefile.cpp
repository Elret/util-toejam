#include "makefile.h"

void Makefile::init_makefile(std::string input_name) {
    std::ofstream file;
    file.open("Makefile");
    file.close();
    file.open(".toejam/toejam");
    file << "#FILE NAMES" << std::endl;
    file << input_name << std::endl;
    file << "#LIBS" << std::endl;
    file.close();
}

void Makefile::create_makefile(std::string input_name) {
    
}