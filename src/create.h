#ifndef CREATE_H
#define CREATE_H

#include <iostream>
#include <fstream>
#include <string>
#include <boost/filesystem.hpp>


class Create {
private:
std::string project_name;
std::string output_cpp();

public:
Create(std::string);
bool create_project();

};
#endif