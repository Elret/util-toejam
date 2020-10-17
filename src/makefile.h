#ifndef MAKEFILE_H
#define MAKEFILE_H

#include <string>
#include <fstream>

#include "linkedlist.h"
#include "file_scan.h"

class Makefile {
    private:
    
    public:
    void create_project_file(std::string);
    void create_makefile(std::string);
    void build_makefile();
};

#endif