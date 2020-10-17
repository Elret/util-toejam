#ifndef MAKEFILE_H
#define MAKEFILE_H

#include <string>
#include <fstream>

class Makefile {
    private:
    
    public:
    void init_file_toejam(std::string);
    void create_makefile(std::string);
    void build_makefile();
};

#endif