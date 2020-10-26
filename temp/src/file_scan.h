#ifndef FILESCAN_H
#define FILESCAN_H

#include <boost/filesystem.hpp>
#include "linkedlist.h"
#include <string>
#include <sstream>
#include <iostream>

class File_Scan {
private:
Linked_List *h_list;
Linked_List *cpp_list;
Linked_List *cpp_list_stem;
std::string pass_string;

public:
File_Scan(Linked_List *h_link, Linked_List *cpp_link, Linked_List *cpp_link_stem);
void search();
int match_file_extension(std::string file_name);
};

#endif