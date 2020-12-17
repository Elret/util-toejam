#ifndef MAKEFILE_H
#define MAKEFILE_H

#include <string>
#include <fstream>

#include "linkedlist.h"
#include "file_scan.h"

class Makefile {
    private:
    std::string return_main_compile_str(std::string project_name);
    std::string return_o_compile_str(std::string o_name, std::string o_stem);
    std::string return_project_name();
    std::string return_project_cflag();
    std::string return_project_libs();
    std::string make_clean();


    public:
    void create_project_file(std::string);
    void create_cflag_file();
    void create_libs_file();
    void create_makefile(std::string);
    void build_makefile();
};

#endif