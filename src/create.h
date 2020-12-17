#ifndef CREATE_H
#define CREATE_H

#include <iostream>
#include <fstream>
#include <string>
#include <boost/filesystem.hpp>
#include "makefile.h"


class Create {
private:
std::string project_name;
std::string output_cpp();
void create_cpp_file();
void create_h_file();
void create_makefile();
void init_project();
void create_project_file();

public:
Create(std::string);
void create_project();
void add_file();
void add_cflag();
void add_lib();
void build();


};
#endif