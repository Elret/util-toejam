#ifndef CREATE_H
#define CREATE_H

#include <string>
#include <boost/filesystem.hpp>
#include <fstream>

class Create {
private:
std::string project_name;
void create_cpp_file();
void create_h_file();

public:
Create(std::string);
bool create_project();
void add_files_to_project();
void create_header_file();
};


#endif