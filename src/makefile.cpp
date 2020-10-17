#include "makefile.h"

void Makefile::init_file_toejam(std::string input_name) {
    std::ofstream file;
    file.open(".toejam/toejam");
    file << "#PROJECT NAME" << std::endl;
    file << input_name << std::endl;
    file << "#FILE NAMES" << std::endl;
    file << "#LIBS" << std::endl;
    file.close();
}

void Makefile::create_makefile(std::string input_name) {
       init_file_toejam(input_name);
       build_makefile();
}

void Makefile::build_makefile() {
    std::ofstream file;
    file.open(".toejam/toejam", std::ios::trunc);

}